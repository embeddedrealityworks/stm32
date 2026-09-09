// SVD to GROOV C++ header generator.
//
// Parses STM32 SVD files and generates GROOV-compatible C++ headers with
// per-MCU register deduplication and bittype classification.
//
// Port of scripts/svd2groov.py. Uses cli23 for argument parsing and
// boost::property_tree for XML.

#include <algorithm>
#include <atomic>
#include <cctype>
#include <charconv>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <map>
#include <mutex>
#include <optional>
#include <print>
#include <set>
#include <span>
#include <string>
#include <string_view>
#include <thread>
#include <vector>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <cli/cli.hpp>

namespace fs = std::filesystem;
namespace pt = boost::property_tree;

// ---------------------------------------------------------------------------
// String helpers
// ---------------------------------------------------------------------------

namespace {

auto to_lower(std::string s) -> std::string {
  for (auto &c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  return s;
}

auto to_upper(std::string s) -> std::string {
  for (auto &c : s) c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
  return s;
}

auto trim(std::string_view s) -> std::string {
  const auto *ws = " \t\r\n";
  auto a = s.find_first_not_of(ws);
  if (a == std::string_view::npos) return {};
  auto b = s.find_last_not_of(ws);
  return std::string{s.substr(a, b - a + 1)};
}

std::mutex g_log_mtx;

template <class... A>
void logln(std::format_string<A...> fmt, A &&...args) {
  std::scoped_lock lock{g_log_mtx};
  std::println(fmt, std::forward<A>(args)...);
}

auto join(const std::vector<std::string> &v, std::string_view sep) -> std::string {
  std::string out;
  for (std::size_t i = 0; i < v.size(); ++i) {
    if (i != 0) out += sep;
    out += v[i];
  }
  return out;
}

// libc++'s std::format / std::sto* funnel through global locale state and do
// not scale across threads, so the hot paths use these locale-free helpers.
auto itoa10(long value) -> std::string {
  char buf[24];
  auto res = std::to_chars(buf, buf + sizeof buf, value);
  return std::string(buf, res.ptr);
}

auto itoa16(unsigned long value) -> std::string {
  char buf[24];
  auto res = std::to_chars(buf, buf + sizeof buf, value, 16);
  return std::string(buf, res.ptr);
}

auto parse_uint(std::string_view s, int base = 10) -> unsigned long {
  unsigned long out = 0;
  std::from_chars(s.data(), s.data() + s.size(), out, base);
  return out;
}

auto is_digits(std::string_view s) -> bool {
  return !s.empty() && std::ranges::all_of(s, [](unsigned char c) {
    return std::isdigit(c) != 0;
  });
}

// Parse an SVD bitRange "[<msb>:<lsb>]". Mirrors Python's re.match(r'\[(\d+):(\d+)\]').
auto parse_bit_range(std::string_view s) -> std::optional<std::pair<int, int>> {
  auto lb = s.find('[');
  if (lb == std::string_view::npos) return std::nullopt;
  auto colon = s.find(':', lb);
  if (colon == std::string_view::npos) return std::nullopt;
  auto rb = s.find(']', colon);
  if (rb == std::string_view::npos) return std::nullopt;
  auto msb = trim(s.substr(lb + 1, colon - lb - 1));
  auto lsb = trim(s.substr(colon + 1, rb - colon - 1));
  if (!is_digits(msb) || !is_digits(lsb)) return std::nullopt;
  return std::pair{static_cast<int>(parse_uint(msb)),
                  static_cast<int>(parse_uint(lsb))};
}

// Strip a trailing "<digits><optional single A-Z>" from a peripheral name,
// lazily (shortest prefix). Mirrors Python's re.match(r'^(.*?)[0-9]+[A-Z]?$').
// Returns the prefix, or nullopt when there is no match / the prefix is empty.
auto strip_periph_index(std::string_view name) -> std::optional<std::string> {
  if (name.empty()) return std::nullopt;
  std::size_t digits_end =
    (std::isupper(static_cast<unsigned char>(name.back())) != 0) ? name.size() - 1
                                                                 : name.size();
  std::size_t i = digits_end;
  while (i > 0 && std::isdigit(static_cast<unsigned char>(name[i - 1])) != 0) --i;
  if (i == digits_end) return std::nullopt; // needs at least one digit
  if (i == 0) return std::nullopt;          // empty prefix
  return std::string{name.substr(0, i)};
}

void extend(std::vector<std::string> &dst, const std::vector<std::string> &src) {
  dst.insert(dst.end(), src.begin(), src.end());
}

// ---------------------------------------------------------------------------
// Data model
// ---------------------------------------------------------------------------

struct Field {
  std::string                name;
  int                        msb = 0;
  int                        lsb = 0;
  std::optional<std::string> access;   // nullopt: inherit from register
  std::string                cpp_type; // resolved C++ type
};

struct Register {
  std::string          name;
  unsigned long        offset = 0;
  std::string          access = "read-write";
  std::vector<Field>   fields;
  std::string          signature;
};

struct Peripheral {
  std::string                name;
  unsigned long              base_address = 0;
  std::string                group_name;
  std::vector<Register>      registers;
  std::optional<std::string> derived_from;
};

struct RegisterTemplate {
  std::string              periph_type;
  std::string              reg_name;
  int                      version = 0;
  std::string              access;
  std::vector<Field>       fields;
  std::vector<std::string> used_by;
  std::string              signature;
};

// ---------------------------------------------------------------------------
// SVD value parsing
// ---------------------------------------------------------------------------

auto parse_int(std::string_view raw) -> unsigned long {
  std::string v = trim(raw);
  if (v.empty()) return 0;
  if (v.size() > 1 && v[0] == '0' && (v[1] == 'x' || v[1] == 'X'))
    return parse_uint(std::string_view{v}.substr(2), 16);
  return parse_uint(v, 10);
}

auto map_access(std::string_view a) -> std::string {
  if (a == "read-write") return "rw";
  if (a == "read-only") return "ro";
  if (a == "write-only") return "wo";
  if (a == "writeOnce") return "wo";
  if (a == "read-writeOnce") return "rw";
  return "rw";
}

auto opt_child(const pt::ptree &node, const std::string &key)
  -> std::optional<std::string> {
  if (auto v = node.get_optional<std::string>(key)) return trim(*v);
  return std::nullopt;
}

auto parse_fields(const pt::ptree &reg_node) -> std::vector<Field> {
  std::vector<Field> fields;
  auto fields_node = reg_node.get_child_optional("fields");
  if (!fields_node) return fields;

  for (const auto &[key, fn] : *fields_node) {
    if (key != "field") continue;
    auto name = opt_child(fn, "name");
    if (!name) continue;

    int msb = 0;
    int lsb = 0;

    auto bit_offset = opt_child(fn, "bitOffset");
    auto bit_width  = opt_child(fn, "bitWidth");
    if (bit_offset && bit_width) {
      long l = static_cast<long>(parse_int(*bit_offset));
      long w = static_cast<long>(parse_int(*bit_width));
      lsb = static_cast<int>(l);
      msb = static_cast<int>(l + w - 1);
    } else if (auto br = opt_child(fn, "bitRange")) {
      auto range = parse_bit_range(*br);
      if (!range) continue;
      msb = range->first;
      lsb = range->second;
    } else {
      auto lsb_s = opt_child(fn, "lsb");
      auto msb_s = opt_child(fn, "msb");
      if (lsb_s && msb_s) {
        lsb = static_cast<int>(parse_int(*lsb_s));
        msb = static_cast<int>(parse_int(*msb_s));
      } else {
        continue;
      }
    }

    Field f;
    f.name   = *name;
    f.msb    = msb;
    f.lsb    = lsb;
    f.access = opt_child(fn, "access");
    fields.push_back(std::move(f));
  }
  return fields;
}

auto parse_register(const pt::ptree &reg_node) -> Register {
  Register r;
  r.name   = trim(reg_node.get<std::string>("name"));
  r.offset = parse_int(reg_node.get<std::string>("addressOffset"));
  if (auto a = opt_child(reg_node, "access")) r.access = *a;
  r.fields = parse_fields(reg_node);
  return r;
}

auto parse_peripheral(const pt::ptree           &node,
                      const std::vector<Peripheral> &order,
                      const std::map<std::string, std::size_t> &pos) -> Peripheral {
  Peripheral p;
  p.name         = trim(node.get<std::string>("name"));
  p.base_address = parse_int(node.get<std::string>("baseAddress"));
  p.derived_from = opt_child(node, "<xmlattr>.derivedFrom");
  if (auto g = opt_child(node, "groupName")) p.group_name = *g;

  auto src_it = p.derived_from ? pos.find(*p.derived_from) : pos.end();
  if (src_it != pos.end()) {
    const Peripheral &src = order[src_it->second];
    for (const auto &reg : src.registers) {
      Register nr;
      nr.name   = reg.name;
      nr.offset = reg.offset;
      nr.access = reg.access;
      for (const auto &f : reg.fields)
        nr.fields.push_back(Field{f.name, f.msb, f.lsb, f.access, ""});
      p.registers.push_back(std::move(nr));
    }
    if (p.group_name.empty()) p.group_name = src.group_name;
  } else if (auto regs_node = node.get_child_optional("registers")) {
    for (const auto &[key, rn] : *regs_node)
      if (key == "register") p.registers.push_back(parse_register(rn));
  }
  return p;
}

auto parse_svd_tree(const pt::ptree &tree) -> std::vector<Peripheral> {
  std::vector<Peripheral>            order;
  std::map<std::string, std::size_t> pos;

  auto periphs = tree.get_child_optional("device.peripherals");
  if (!periphs) return order;

  auto add = [&](Peripheral &&p) {
    auto it = pos.find(p.name);
    if (it != pos.end()) {
      order[it->second] = std::move(p);
    } else {
      pos.emplace(p.name, order.size());
      order.push_back(std::move(p));
    }
  };

  for (const auto &[key, pn] : *periphs) {
    if (key != "peripheral") continue;
    if (pn.get_optional<std::string>("<xmlattr>.derivedFrom")) continue;
    add(parse_peripheral(pn, order, pos));
  }
  for (const auto &[key, pn] : *periphs) {
    if (key != "peripheral") continue;
    if (!pn.get_optional<std::string>("<xmlattr>.derivedFrom")) continue;
    add(parse_peripheral(pn, order, pos));
  }
  return order;
}

auto read_svd(const std::string &path) -> pt::ptree {
  pt::ptree tree;
  pt::read_xml(path, tree,
               pt::xml_parser::trim_whitespace | pt::xml_parser::no_comments);
  return tree;
}

auto mcu_name_from_tree(const pt::ptree &tree, const std::string &path)
  -> std::string {
  if (auto n = tree.get_optional<std::string>("device.name"))
    return to_lower(trim(*n));
  return to_lower(fs::path{path}.stem().string());
}

auto cpu_variant_from_tree(const pt::ptree &tree) -> std::string {
  static const std::map<std::string, std::string> kMap{
    {"CM0", "cm0"},    {"CM0+", "cm0p"}, {"CM3", "cm3"},   {"CM4", "cm4"},
    {"CM7", "cm7"},    {"CM23", "cm0p"}, {"CM33", "cm33"}, {"CM35P", "cm33"},
    {"CM55", "cm55"},  {"CM85", "cm55"},
  };
  auto name = tree.get_optional<std::string>("device.cpu.name");
  if (!name) return {};
  auto it = kMap.find(trim(*name));
  return it == kMap.end() ? std::string{} : it->second;
}

// Longest/most-specific prefix first: 'wba' before 'wb'.
const std::vector<std::string> kFamilyPrefixes{
  "wba", "wb", "wl", "c0", "f0", "f1", "f2", "f3", "f4", "f7",
  "g0",  "g4", "h5", "h7", "l0", "l1", "l4", "l5", "n6", "u0", "u3", "u5",
};

auto family_from_mcu(const std::string &mcu) -> std::string {
  std::string stem = mcu;
  if (stem.starts_with("stm32")) stem = stem.substr(5);
  for (const auto &fam : kFamilyPrefixes)
    if (stem.starts_with(fam)) return fam;
  return mcu; // no known family -> own bucket
}

// ---------------------------------------------------------------------------
// Bittype classification
// ---------------------------------------------------------------------------

auto classify_bittype(const std::string &field_name) -> std::string {
  const std::string name = to_upper(field_name);
  const std::string p    = "common::";

  auto ends = [&](std::string_view s) { return name.ends_with(s); };
  auto has  = [&](std::string_view s) { return name.find(s) != std::string::npos; };

  if (ends("RST")) return p + "bit_reset";
  if (has("LOCK") || ends("LCK")) return p + "bit_locked";
  if (has("RDY")) return p + "bit_ready";
  if (has("BSY")) return p + "bit_nready";
  if (ends("DIS")) return p + "bit_nenable";
  if (ends("EN")) return p + "bit_enable";
  if (ends("IE")) return p + "bit_enable";
  if (ends("DE")) return p + "bit_enable";
  if (ends("PE")) return p + "bit_enable";
  if (ends("FE")) return p + "bit_enable";
  if (name.size() >= 2 && name[name.size() - 1] == 'E' &&
      std::isdigit(static_cast<unsigned char>(name[name.size() - 2])))
    return p + "bit_enable";

  return "bool";
}

auto bit_width_to_type(int width, const std::string &field_name = "")
  -> std::string {
  if (width == 1) return classify_bittype(field_name);
  if (width <= 8) return "std::uint8_t";
  if (width <= 16) return "std::uint16_t";
  return "std::uint32_t";
}

// ---------------------------------------------------------------------------
// Reserved fields
// ---------------------------------------------------------------------------

auto generate_reserved_fields(const std::vector<Field> &defined,
                              int register_width = 32) -> std::vector<Field> {
  std::vector<bool> bit_defined(register_width, false);
  for (const auto &f : defined)
    for (int b = f.lsb; b <= f.msb; ++b)
      if (b >= 0 && b < register_width) bit_defined[b] = true;

  std::vector<Field> reserved;
  int  idx       = 0;
  bool in_gap    = false;
  int  gap_start = 0;

  for (int b = 0; b < register_width; ++b) {
    if (!bit_defined[b]) {
      if (!in_gap) {
        in_gap    = true;
        gap_start = b;
      }
    } else if (in_gap) {
      reserved.push_back(Field{"RESERVED" + std::to_string(idx), b - 1, gap_start,
                               std::string{"read-only"}, ""});
      ++idx;
      in_gap = false;
    }
  }
  if (in_gap)
    reserved.push_back(Field{"RESERVED" + std::to_string(idx), register_width - 1,
                             gap_start, std::string{"read-only"}, ""});
  return reserved;
}

// ---------------------------------------------------------------------------
// Signature computation & deduplication
// ---------------------------------------------------------------------------

void resolve_field_types(Register &reg) {
  for (auto &f : reg.fields)
    f.cpp_type = bit_width_to_type(f.msb - f.lsb + 1, f.name);
}

// The signature is used only as an in-process dedup key, so the raw string
// stands in for the Python version's MD5 digest.
auto compute_signature(const Register &reg) -> std::string {
  std::vector<std::string> parts{map_access(reg.access)};

  std::vector<Field> all = reg.fields;
  for (auto &r : generate_reserved_fields(reg.fields)) all.push_back(std::move(r));
  std::sort(all.begin(), all.end(),
            [](const Field &a, const Field &b) { return a.lsb < b.lsb; });

  for (const auto &f : all) {
    int         width = f.msb - f.lsb + 1;
    std::string cpp_type =
      f.cpp_type.empty() ? bit_width_to_type(width, f.name) : f.cpp_type;
    std::string field_access = f.access ? map_access(*f.access) : std::string{};
    parts.push_back(std::format("{}:{}:{}:{}:{}", f.name, f.msb, f.lsb,
                                field_access, cpp_type));
  }
  return join(parts, "|");
}

struct RegisterRegistry {
  std::map<std::string, RegisterTemplate>           sig_to_template;
  std::map<std::pair<std::string, std::string>, int> version_counters;

  void get_or_create(const std::string &ptype, const std::string &reg_name,
                     const std::string &sig, const Register &reg,
                     const std::string &label) {
    auto it = sig_to_template.find(sig);
    if (it == sig_to_template.end()) {
      int ver = ++version_counters[{ptype, reg_name}];

      RegisterTemplate tmpl;
      tmpl.periph_type = ptype;
      tmpl.reg_name    = reg_name;
      tmpl.version     = ver;
      tmpl.access      = reg.access;
      tmpl.signature   = sig;
      tmpl.used_by     = {label};

      for (const auto &f : reg.fields)
        tmpl.fields.push_back(Field{f.name, f.msb, f.lsb, f.access, f.cpp_type});
      for (auto &rf : generate_reserved_fields(reg.fields)) {
        rf.cpp_type = bit_width_to_type(rf.msb - rf.lsb + 1, rf.name);
        tmpl.fields.push_back(std::move(rf));
      }
      std::sort(tmpl.fields.begin(), tmpl.fields.end(),
                [](const Field &a, const Field &b) { return a.msb > b.msb; });

      sig_to_template.emplace(sig, std::move(tmpl));
    } else {
      auto &used = it->second.used_by;
      if (std::find(used.begin(), used.end(), label) == used.end())
        used.push_back(label);
    }
  }
};

// ---------------------------------------------------------------------------
// Peripheral type normalization
// ---------------------------------------------------------------------------

auto normalize_periph_type(const Peripheral &p) -> std::string {
  static const std::map<std::string, std::string> kGroupMap{
    {"OTG_FS", "otg_fs"},
    {"OTG_HS", "otg_hs"},
    {"USB_OTG_FS", "usb_otg_fs"},
    {"USB_OTG_HS", "usb_otg_hs"},
  };
  if (auto it = kGroupMap.find(p.name); it != kGroupMap.end()) return it->second;
  if (!p.group_name.empty()) return to_lower(p.group_name);

  if (auto prefix = strip_periph_index(p.name)) return to_lower(*prefix);

  return to_lower(p.name);
}

// ---------------------------------------------------------------------------
// Code generation helpers
// ---------------------------------------------------------------------------

auto format_address(unsigned long addr) -> std::string {
  std::string hex = itoa16(addr);
  if (hex.size() < 8) hex.insert(0, 8 - hex.size(), '0');
  return "0x" + hex.substr(0, 4) + "'" + hex.substr(4);
}

auto format_offset(unsigned long offset) -> std::string {
  if (offset == 0) return "0x0";
  return "0x" + itoa16(offset);
}

auto field_line(const Field &f, const std::string &register_access, bool is_last)
  -> std::string {
  int         width = f.msb - f.lsb + 1;
  std::string cpp_type =
    f.cpp_type.empty() ? bit_width_to_type(width, f.name) : f.cpp_type;

  std::string access_str;
  if (f.access) {
    std::string ga = map_access(*f.access);
    if (ga != map_access(register_access))
      access_str = ", common::access::" + ga;
  }

  std::string out(15, ' ');
  out += "groov::field<\"";
  out += to_lower(f.name);
  out += "\", ";
  out += cpp_type;
  out += ", ";
  out += itoa10(f.msb);
  out += ", ";
  out += itoa10(f.lsb);
  out += access_str;
  out += is_last ? ">" : ">,";
  return out;
}

// ---------------------------------------------------------------------------
// Per-MCU processing (parse only, no I/O)
// ---------------------------------------------------------------------------

struct MCUData {
  std::string mcu;
  std::string cpu_variant;

  std::vector<Peripheral>            peripherals;
  std::map<std::string, std::string> periph_types; // periph name -> ptype

  std::map<std::string, std::vector<const Peripheral *>> type_peripherals;
  std::map<std::string, std::optional<std::string>>      shared_ns; // periph -> ns
  std::map<std::string, const Peripheral *>              shared_representative;
  std::map<std::pair<std::string, std::string>, std::string> reg_template_map;

  RegisterRegistry registry;
  int              total_regs = 0;
};

auto collect_mcu(const std::string &svd_path, bool verbose) -> MCUData {
  MCUData data;
  pt::ptree tree = read_svd(svd_path);

  data.mcu         = mcu_name_from_tree(tree, svd_path);
  data.cpu_variant = cpu_variant_from_tree(tree);
  if (verbose) logln("Processing {} from {}", data.mcu, svd_path);

  data.peripherals = parse_svd_tree(tree);

  for (auto &p : data.peripherals)
    for (auto &reg : p.registers) {
      resolve_field_types(reg);
      reg.signature = compute_signature(reg);
    }

  for (const auto &p : data.peripherals)
    data.periph_types[p.name] = normalize_periph_type(p);

  for (const auto &p : data.peripherals) {
    const std::string &ptype = data.periph_types[p.name];
    for (const auto &reg : p.registers) {
      ++data.total_regs;
      std::string label = data.mcu + "::" + p.name;
      data.registry.get_or_create(ptype, to_lower(reg.name), reg.signature, reg,
                                  label);
      data.reg_template_map[{p.name, reg.name}] = reg.signature;
    }
  }

  for (const auto &p : data.peripherals)
    data.type_peripherals[data.periph_types[p.name]].push_back(&p);

  std::map<std::string, const Peripheral *> periph_by_name;
  for (const auto &p : data.peripherals) periph_by_name[p.name] = &p;

  for (const auto &[ptype, p_list] : data.type_peripherals) {
    std::set<std::string> ptype_names;
    for (const auto *p : p_list) ptype_names.insert(p->name);

    auto derived_within = [&](const Peripheral *p) {
      return p->derived_from && ptype_names.contains(*p->derived_from);
    };

    std::map<std::string, std::vector<std::string>> children;
    for (const auto *p : p_list)
      if (derived_within(p)) children[*p->derived_from].push_back(p->name);

    std::set<std::string>                        in_group;
    std::vector<std::vector<const Peripheral *>> groups;
    for (const auto *p : p_list) {
      auto ch = children.find(p->name);
      if (ch != children.end() && !ch->second.empty() && !derived_within(p)) {
        std::vector<const Peripheral *> group{p};
        for (const auto &c : ch->second) group.push_back(periph_by_name[c]);
        for (const auto *member : group) in_group.insert(member->name);
        groups.push_back(std::move(group));
      }
    }

    if (groups.size() == 1) {
      std::string ns = ptype + "x";
      data.shared_representative[ns] = groups[0][0];
      for (const auto *p : groups[0]) data.shared_ns[p->name] = ns;
    } else if (groups.size() > 1) {
      for (std::size_t i = 0; i < groups.size(); ++i) {
        std::string ns =
          i == 0 ? ptype + "x" : std::format("{}x_v{}", ptype, i + 1);
        data.shared_representative[ns] = groups[i][0];
        for (const auto *p : groups[i]) data.shared_ns[p->name] = ns;
      }
    }

    for (const auto *p : p_list)
      if (!in_group.contains(p->name)) data.shared_ns[p->name] = std::nullopt;
  }

  if (verbose)
    logln("  {} peripherals, {} registers, {} unique templates",
          data.peripherals.size(), data.total_regs,
          data.registry.sig_to_template.size());

  return data;
}

// ---------------------------------------------------------------------------
// Code generation: register templates (inlined into peripheral headers)
// ---------------------------------------------------------------------------

auto template_stem(const RegisterTemplate &t) -> std::string {
  return t.periph_type + "_" + t.reg_name + "_v" + itoa10(t.version);
}

auto template_name(const RegisterTemplate &t) -> std::string {
  return template_stem(t) + "_tt";
}

auto register_template_lines(const std::vector<const RegisterTemplate *> &templates)
  -> std::vector<std::string> {
  std::vector<std::string> lines{"namespace regs {"};

  for (const auto *tmpl : templates) {
    lines.push_back("");
    std::string stem  = template_stem(*tmpl);
    std::string tname = stem + "_tt";
    lines.push_back("// " + stem + ": " + to_upper(tmpl->reg_name));
    lines.push_back("template <stdx::ct_string name,");
    lines.push_back(std::string(10, ' ') + "std::uint32_t   baseaddress,");
    lines.push_back(std::string(10, ' ') + "std::uint32_t   offset>");
    lines.push_back("using " + tname + " =");

    lines.push_back("  groov::reg<name,");
    lines.push_back(std::string(13, ' ') + "std::uint32_t,");
    lines.push_back(std::string(13, ' ') + "baseaddress + offset,");
    lines.push_back(std::string(13, ' ') + "common::access::" +
                    map_access(tmpl->access) + ",");

    for (std::size_t i = 0; i < tmpl->fields.size(); ++i) {
      bool        is_last = i + 1 == tmpl->fields.size();
      std::string line    = field_line(tmpl->fields[i], tmpl->access, is_last);
      if (is_last) line += ">;";
      lines.push_back(line);
    }
  }

  lines.push_back("");
  lines.push_back("} // namespace regs");
  return lines;
}

// ---------------------------------------------------------------------------
// Code generation: peripheral headers
// ---------------------------------------------------------------------------

void emit_peripheral_namespace(
  std::vector<std::string> &lines, const Peripheral &p,
  const std::string &name_label, const std::string &ns_name,
  const std::map<std::pair<std::string, std::string>, std::string> &reg_template_map,
  const std::map<std::string, RegisterTemplate> &sig_to_template, bool shared) {
  lines.push_back("");
  lines.push_back(std::format("namespace {} {{", ns_name));

  struct Alias {
    std::string   alias;
    std::string   reg_lower;
    unsigned long offset;
  };
  std::vector<Alias> reg_aliases;

  for (const auto &reg : p.registers) {
    const std::string      &sig  = reg_template_map.at({p.name, reg.name});
    const RegisterTemplate  &tmpl = sig_to_template.at(sig);
    std::string             tname = template_name(tmpl);
    std::string             alias = to_lower(reg.name) + "_tt";
    lines.push_back("  template <stdx::ct_string name,");
    lines.push_back(std::string(12, ' ') + "std::uint32_t   baseaddress,");
    lines.push_back(std::string(12, ' ') + "std::uint32_t   offset>");
    lines.push_back("  using " + alias + " = regs::" + tname +
                    "<name, baseaddress, offset>;");
    reg_aliases.push_back({alias, to_lower(reg.name), reg.offset});
  }

  lines.push_back("");

  if (shared) {
    lines.push_back("  template <stdx::ct_string name, std::uint32_t baseaddress>");
    lines.push_back(std::format("  using {}_t =", ns_name));
    lines.push_back("    groov::group<name,");
  } else {
    lines.push_back("  template <std::uint32_t baseaddress>");
    lines.push_back(std::format("  using {}_t =", ns_name));
    lines.push_back(std::format("    groov::group<\"{}\",", name_label));
  }

  lines.push_back(std::string(17, ' ') + "groov::mmio_bus<>,");

  for (std::size_t i = 0; i < reg_aliases.size(); ++i) {
    const auto &a     = reg_aliases[i];
    const char *comma = i + 1 == reg_aliases.size() ? ">;" : ",";
    lines.push_back(std::string(17, ' ') + a.alias + "<\"" + a.reg_lower +
                    "\", baseaddress, " + format_offset(a.offset) + ">" + comma);
  }

  lines.push_back("");
  lines.push_back(std::format("}} // namespace {}", ns_name));
}

auto peripheral_body_lines(
  const std::vector<const Peripheral *> &peripherals,
  const std::map<std::pair<std::string, std::string>, std::string> &reg_template_map,
  const std::map<std::string, RegisterTemplate>            &sig_to_template,
  const std::map<std::string, std::optional<std::string>>  &shared_ns,
  const std::map<std::string, const Peripheral *>          &shared_representative)
  -> std::vector<std::string> {
  std::vector<std::string> lines;
  std::set<std::string>    emitted_shared;

  for (const auto *p : peripherals) {
    const auto &ns = shared_ns.at(p->name);
    if (ns && !emitted_shared.contains(*ns)) {
      emit_peripheral_namespace(lines, *shared_representative.at(*ns), *ns, *ns,
                                reg_template_map, sig_to_template, true);
      emitted_shared.insert(*ns);
    }
  }

  for (const auto *p : peripherals) {
    if (!shared_ns.at(p->name)) {
      std::string p_lower = to_lower(p->name);
      emit_peripheral_namespace(lines, *p, p_lower, p_lower, reg_template_map,
                                sig_to_template, false);
    }
  }

  return lines;
}

auto generate_peripheral_file(
  const std::string &mcu, const std::string &ptype,
  const std::vector<const Peripheral *> &peripherals,
  const std::map<std::pair<std::string, std::string>, std::string> &reg_template_map,
  const std::map<std::string, RegisterTemplate>            &sig_to_template,
  const std::map<std::string, std::optional<std::string>>  &shared_ns,
  const std::map<std::string, const Peripheral *>          &shared_representative)
  -> std::string {
  std::vector<const RegisterTemplate *> templates;
  for (const auto &[sig, tmpl] : sig_to_template)
    if (tmpl.periph_type == ptype) templates.push_back(&tmpl);
  std::sort(templates.begin(), templates.end(),
            [](const RegisterTemplate *a, const RegisterTemplate *b) {
              return std::tie(a->reg_name, a->version) <
                     std::tie(b->reg_name, b->version);
            });

  std::vector<std::string> lines{
    "/* File autogenerated with svd2groov */",
    "#pragma once",
    "#include <groov/groov.hpp>",
    "#include \"../../common/access.hpp\"",
    "#include \"../../common/bittypes.hpp\"",
    std::format("namespace erworks::stm32::{} {{", mcu),
  };
  extend(lines, register_template_lines(templates));
  extend(lines, peripheral_body_lines(peripherals, reg_template_map,
                                      sig_to_template, shared_ns,
                                      shared_representative));
  lines.push_back(std::format("}} // namespace erworks::stm32::{}", mcu));
  lines.push_back("");
  return join(lines, "\n");
}

// ---------------------------------------------------------------------------
// Code generation: addresses header
// ---------------------------------------------------------------------------

auto by_name_lower(std::vector<const Peripheral *> v)
  -> std::vector<const Peripheral *> {
  std::stable_sort(v.begin(), v.end(),
                   [](const Peripheral *a, const Peripheral *b) {
                     return to_lower(a->name) < to_lower(b->name);
                   });
  return v;
}

auto generate_addresses_header(const std::string             &mcu,
                               const std::vector<Peripheral> &peripherals)
  -> std::string {
  std::vector<std::string> lines{
    "/* File autogenerated with svd2groov */",
    "#pragma once",
    "",
    "#include <cstdint>",
    "",
    std::format("namespace erworks::stm32::{} {{", mcu),
  };

  std::vector<const Peripheral *> sorted;
  for (const auto &p : peripherals) sorted.push_back(&p);
  for (const auto *p : by_name_lower(std::move(sorted))) {
    std::string p_lower = to_lower(p->name);
    std::string p_upper = to_upper(p->name);
    lines.push_back(std::format(
      "namespace {} {{ inline constexpr std::uint32_t {}_BASE = {}; }} "
      "// namespace {}",
      p_lower, p_upper, format_address(p->base_address), p_lower));
  }

  lines.push_back("");
  lines.push_back(std::format("}} // namespace erworks::stm32::{}", mcu));
  lines.push_back("");
  return join(lines, "\n");
}

// ---------------------------------------------------------------------------
// Code generation: MCU aggregate
// ---------------------------------------------------------------------------

auto generate_aggregate(
  const std::string &mcu, const std::string &cpu_variant,
  const std::vector<Peripheral>                         &peripherals,
  const std::map<std::string, std::vector<const Peripheral *>> &type_peripherals,
  const std::map<std::string, std::optional<std::string>>      &shared_ns)
  -> std::string {
  std::vector<std::string> lines{
    std::format("/* File autogenerated with svd2groov for {} */", mcu),
    "#pragma once",
    "",
  };

  for (const auto &[ptype, _] : type_peripherals)
    lines.push_back(std::format("#include \"{}/{}.hpp\"", mcu, ptype));
  lines.push_back("");
  lines.push_back(std::format("#include \"{}/addresses.hpp\"", mcu));
  if (!cpu_variant.empty())
    lines.push_back(std::format("#include \"../core/{}.hpp\"", cpu_variant));
  lines.push_back("");
  lines.push_back("namespace erworks::stm32 {");

  std::vector<const Peripheral *> sorted;
  for (const auto &p : peripherals) sorted.push_back(&p);
  for (const auto *p : by_name_lower(std::move(sorted))) {
    std::string p_lower = to_lower(p->name);
    std::string p_upper = to_upper(p->name);
    const auto &ns      = shared_ns.at(p->name);

    lines.push_back("");
    if (ns) {
      lines.push_back(std::format(
        "constexpr auto {} = {}::{}::{}_t<\"{}\",{}::{}::{}_BASE>{{}};", p_lower,
        mcu, *ns, *ns, p_lower, mcu, p_lower, p_upper));
    } else {
      lines.push_back(std::format(
        "constexpr auto {} = {}::{}::{}_t<{}::{}::{}_BASE>{{}};", p_lower, mcu,
        p_lower, p_lower, mcu, p_lower, p_upper));
    }
  }

  lines.push_back("");
  lines.push_back("} // namespace erworks::stm32");
  lines.push_back("");
  return join(lines, "\n");
}

// ---------------------------------------------------------------------------
// MCU file emission
// ---------------------------------------------------------------------------

void write_file(const fs::path &path, const std::string &content) {
  std::ofstream out{path, std::ios::binary};
  out << content;
}

void emit_mcu_files(const MCUData &data, const fs::path &output_base,
                    bool verbose) {
  fs::path family_dir = output_base / family_from_mcu(data.mcu);
  fs::path mcu_dir    = family_dir / data.mcu;

  // Fully regenerated, nothing hand-written: wipe stale layout.
  // ec overloads: mcu_dir is unique per thread; family_dir may be created
  // concurrently by siblings of the same family — a benign race.
  std::error_code ec;
  fs::remove_all(mcu_dir, ec);
  fs::create_directories(mcu_dir, ec);

  for (const auto &[ptype, p_list] : data.type_peripherals) {
    std::string content = generate_peripheral_file(
      data.mcu, ptype, p_list, data.reg_template_map,
      data.registry.sig_to_template, data.shared_ns, data.shared_representative);
    write_file(mcu_dir / (ptype + ".hpp"), content);
  }

  write_file(mcu_dir / "addresses.hpp",
             generate_addresses_header(data.mcu, data.peripherals));

  write_file(family_dir / (data.mcu + ".hpp"),
             generate_aggregate(data.mcu, data.cpu_variant, data.peripherals,
                                data.type_peripherals, data.shared_ns));

  if (verbose)
    logln("  emitted {} peripheral files", data.type_peripherals.size());
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------

void list_peripherals(const std::string &svd_path) {
  auto peripherals = parse_svd_tree(read_svd(svd_path));
  std::vector<std::string> names;
  for (const auto &p : peripherals) names.push_back(to_lower(p.name));
  std::sort(names.begin(), names.end());
  for (const auto &n : names) std::println("{}", n);
}

} // namespace

auto main(int argc, char *argv[]) -> int {
  cli::Parser parser{"svd2groov",
                     "Generate GROOV C++ headers from STM32 SVD files"};
  parser.flag("--help").help("Show this help and exit");
  parser.option<std::string>("--output")
    .alias("-o")
    .help("Output base directory (e.g. include/stm32/)");
  parser.flag("--verbose").help("Print per-file progress");
  parser.flag("--stats").help("Print deduplication statistics at end");
  parser.option<int>("--jobs")
    .alias("-j")
    .help("Worker threads (0 = hardware concurrency)")
    .default_value(0);
  parser.flag("--list-peripherals")
    .help("Print peripheral names (one per line) and exit");

  auto result = parser.parse_or_exit(argc, argv);

  if (result.get<bool>("--help")) {
    parser.print_help();
    return 0;
  }

  const bool verbose = result.get<bool>("--verbose");
  const auto svd_files = result.positional();

  if (svd_files.empty()) {
    std::println(stderr, "error: no SVD files given");
    return 1;
  }

  if (result.get<bool>("--list-peripherals")) {
    for (const auto &path : svd_files) list_peripherals(path);
    return 0;
  }

  auto output = result.get_optional<std::string>("--output");
  if (!output) {
    std::println(stderr, "error: required option '--output' not provided");
    return 1;
  }
  const fs::path output_base{*output};

  // Drop the old cross-MCU shared trees (registers now inlined per-MCU).
  for (const char *sub : {"registers", "peripherals"}) {
    std::error_code ec;
    fs::remove_all(output_base / "common" / sub, ec);
  }

  // Each MCU is independent (own registry, own output dir), so process them
  // on a pool of worker threads pulling from a shared index.
  const std::size_t   count = svd_files.size();
  std::vector<MCUData> all_mcu_data(count);
  std::atomic<std::size_t> next{0};

  auto worker = [&] {
    for (std::size_t i = next.fetch_add(1); i < count;
         i = next.fetch_add(1)) {
      all_mcu_data[i] = collect_mcu(svd_files[i], verbose);
      emit_mcu_files(all_mcu_data[i], output_base, verbose);
    }
  };

  int jobs = result.get<int>("--jobs");
  if (jobs <= 0) {
    unsigned hw = std::thread::hardware_concurrency();
    jobs = static_cast<int>(hw != 0U ? hw : 4);
  }
  std::size_t nthreads = std::min<std::size_t>(static_cast<std::size_t>(jobs), count);

  if (nthreads <= 1) {
    worker();
  } else {
    std::vector<std::jthread> pool;
    pool.reserve(nthreads);
    for (std::size_t t = 0; t < nthreads; ++t) pool.emplace_back(worker);
    pool.clear(); // join all
  }

  if (result.get<bool>("--stats")) {
    long total_regs = 0;
    long total_tmpl = 0;
    long total_hdrs = 0;
    for (const auto &d : all_mcu_data) {
      total_regs += d.total_regs;
      total_tmpl += static_cast<long>(d.registry.sig_to_template.size());
      total_hdrs += static_cast<long>(d.type_peripherals.size());
    }

    std::println("\n--- Statistics ---");
    std::println("MCUs processed:          {}", all_mcu_data.size());
    std::println("Total registers:         {}", total_regs);
    std::println("Per-MCU unique templates:{}", total_tmpl);
    if (total_regs > 0) {
      double ratio = (1.0 - static_cast<double>(total_tmpl) / total_regs) * 100.0;
      std::println("Register dedup ratio:    {:.1f}% ({} duplicates eliminated)",
                   ratio, total_regs - total_tmpl);
    }
    std::println("Per-MCU periph headers:  {}", total_hdrs);
  }

  return 0;
}
