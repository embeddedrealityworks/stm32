#!/usr/bin/env python3
"""
SVD to GROOV C++ header generator.

Parses STM32 SVD files and generates GROOV-compatible C++ headers
with cross-MCU register deduplication and bittype classification.
"""

import argparse
import hashlib
import re
import shutil
import xml.etree.ElementTree as ET
from collections import defaultdict
from dataclasses import dataclass, field
from pathlib import Path


# ---------------------------------------------------------------------------
# Data model
# ---------------------------------------------------------------------------

@dataclass
class Field:
    """Represents a register field."""
    name: str
    msb: int
    lsb: int
    access: str | None = None  # None means inherit from register
    cpp_type: str = ""         # Resolved C++ type (set after classification)


@dataclass
class Register:
    """Represents a peripheral register."""
    name: str
    offset: int
    access: str
    fields: list[Field] = field(default_factory=list)
    signature: str = ""


@dataclass
class Peripheral:
    """Represents a peripheral."""
    name: str
    base_address: int
    group_name: str = ""
    registers: list[Register] = field(default_factory=list)
    derived_from: str | None = None


@dataclass
class RegisterTemplate:
    """A deduplicated register template."""
    periph_type: str        # Normalized peripheral type (e.g. "tim")
    reg_name: str           # Register name (e.g. "cr1")
    version: int            # Global version number (same layout = same version)
    access: str             # Register-level access
    fields: list[Field]     # All fields (including reserved)
    used_by: list[str] = field(default_factory=list)  # "mcu::PERIPH" labels
    signature: str = ""


@dataclass
class GlobalRegistry:
    """Cross-MCU register template registry for deduplication."""
    sig_to_template: dict[str, RegisterTemplate] = field(default_factory=dict)
    version_counters: dict[tuple[str, str], int] = field(
        default_factory=lambda: defaultdict(int))

    def get_or_create(
        self,
        ptype: str,
        reg_name: str,
        sig: str,
        reg: 'Register',
        label: str,
    ) -> 'RegisterTemplate':
        if sig not in self.sig_to_template:
            self.version_counters[(ptype, reg_name)] += 1
            ver = self.version_counters[(ptype, reg_name)]
            all_fields = [
                Field(name=f.name, msb=f.msb, lsb=f.lsb,
                      access=f.access, cpp_type=f.cpp_type)
                for f in reg.fields
            ]
            reserved = generate_reserved_fields(reg.fields)
            for rf in reserved:
                w = rf.msb - rf.lsb + 1
                rf.cpp_type = bit_width_to_type(w, rf.name)
                all_fields.append(rf)
            all_fields.sort(key=lambda x: x.msb, reverse=True)
            self.sig_to_template[sig] = RegisterTemplate(
                periph_type=ptype,
                reg_name=reg_name,
                version=ver,
                access=reg.access,
                fields=all_fields,
                used_by=[label],
                signature=sig,
            )
        else:
            tmpl = self.sig_to_template[sig]
            if label not in tmpl.used_by:
                tmpl.used_by.append(label)
        return self.sig_to_template[sig]


_SVD_CPU_MAP: dict[str, str] = {
    'CM0':   'cm0',
    'CM0+':  'cm0p',
    'CM3':   'cm3',
    'CM4':   'cm4',
    'CM7':   'cm7',
    'CM23':  'cm0p',
    'CM33':  'cm33',
    'CM35P': 'cm33',
    'CM55':  'cm55',
    'CM85':  'cm55',
}


@dataclass
class MCUData:
    """Per-MCU processing results (no I/O)."""
    mcu: str
    cpu_variant: str            # e.g. "cm4" — key into common/core/
    peripherals: list[Peripheral]
    periph_types: dict[str, str]
    type_peripherals: dict[str, list[Peripheral]]
    shared_ns: dict[str, str | None]
    shared_representative: dict[str, Peripheral]
    reg_template_map: dict[tuple[str, str], str]  # (periph, reg) -> sig
    total_regs: int
    new_global_templates: int


# ---------------------------------------------------------------------------
# SVD parsing
# ---------------------------------------------------------------------------

def parse_int(value: str) -> int:
    """Parse an integer from SVD format (supports 0x prefix)."""
    if value is None:
        return 0
    value = value.strip()
    if value.startswith(('0x', '0X')):
        return int(value, 16)
    return int(value)


def map_access(svd_access: str | None) -> str:
    """Map SVD access type to GROOV access type."""
    if svd_access is None:
        return 'rw'
    mapping = {
        'read-write': 'rw',
        'read-only': 'ro',
        'write-only': 'wo',
        'writeOnce': 'wo',
        'read-writeOnce': 'rw',
    }
    return mapping.get(svd_access, 'rw')


def parse_fields(register_elem: ET.Element) -> list[Field]:
    """Parse fields from a register element."""
    fields = []
    fields_elem = register_elem.find('fields')
    if fields_elem is None:
        return fields

    for field_elem in fields_elem.findall('field'):
        name = field_elem.find('name').text

        bit_offset_elem = field_elem.find('bitOffset')
        bit_width_elem = field_elem.find('bitWidth')

        if bit_offset_elem is not None and bit_width_elem is not None:
            lsb = parse_int(bit_offset_elem.text)
            width = parse_int(bit_width_elem.text)
            msb = lsb + width - 1
        else:
            bit_range_elem = field_elem.find('bitRange')
            if bit_range_elem is not None:
                match = re.match(r'\[(\d+):(\d+)\]', bit_range_elem.text)
                if match:
                    msb = int(match.group(1))
                    lsb = int(match.group(2))
                else:
                    continue
            else:
                lsb_elem = field_elem.find('lsb')
                msb_elem = field_elem.find('msb')
                if lsb_elem is not None and msb_elem is not None:
                    lsb = parse_int(lsb_elem.text)
                    msb = parse_int(msb_elem.text)
                else:
                    continue

        access_elem = field_elem.find('access')
        access = access_elem.text if access_elem is not None else None

        fields.append(Field(name=name, msb=msb, lsb=lsb, access=access))

    return fields


def parse_register(register_elem: ET.Element) -> Register:
    """Parse a register from an XML element."""
    name = register_elem.find('name').text
    offset = parse_int(register_elem.find('addressOffset').text)

    access_elem = register_elem.find('access')
    access = access_elem.text if access_elem is not None else 'read-write'

    fields = parse_fields(register_elem)
    return Register(name=name, offset=offset, access=access, fields=fields)


def parse_peripheral(
    peripheral_elem: ET.Element,
    all_peripherals: dict[str, Peripheral]
) -> Peripheral:
    """Parse a peripheral from an XML element."""
    name = peripheral_elem.find('name').text
    base_address = parse_int(peripheral_elem.find('baseAddress').text)
    derived_from = peripheral_elem.get('derivedFrom')

    group_elem = peripheral_elem.find('groupName')
    group_name = group_elem.text if group_elem is not None else ""

    registers = []
    if derived_from and derived_from in all_peripherals:
        source = all_peripherals[derived_from]
        for reg in source.registers:
            registers.append(Register(
                name=reg.name,
                offset=reg.offset,
                access=reg.access,
                fields=[Field(name=f.name, msb=f.msb, lsb=f.lsb,
                              access=f.access)
                        for f in reg.fields]
            ))
        if not group_name:
            group_name = source.group_name
    else:
        registers_elem = peripheral_elem.find('registers')
        if registers_elem is not None:
            for register_elem in registers_elem.findall('register'):
                registers.append(parse_register(register_elem))

    return Peripheral(
        name=name,
        base_address=base_address,
        group_name=group_name,
        registers=registers,
        derived_from=derived_from,
    )


def parse_svd(filename: str) -> list[Peripheral]:
    """Parse an SVD file and return list of peripherals."""
    tree = ET.parse(filename)
    root = tree.getroot()

    peripherals = {}
    peripherals_elem = root.find('peripherals')
    if peripherals_elem is None:
        return []

    for elem in peripherals_elem.findall('peripheral'):
        if elem.get('derivedFrom') is None:
            p = parse_peripheral(elem, peripherals)
            peripherals[p.name] = p

    for elem in peripherals_elem.findall('peripheral'):
        if elem.get('derivedFrom') is not None:
            p = parse_peripheral(elem, peripherals)
            peripherals[p.name] = p

    return list(peripherals.values())


def mcu_name_from_svd(svd_path: str) -> str:
    """Extract MCU name from SVD file."""
    tree = ET.parse(svd_path)
    root = tree.getroot()
    name_elem = root.find('name')
    if name_elem is not None:
        return name_elem.text.lower()
    return Path(svd_path).stem.lower()


# Longest/most-specific prefix first: 'wba' must be checked before 'wb',
# since e.g. 'stm32wba52' starts with both.
FAMILY_PREFIXES = [
    'wba', 'wb', 'wl',
    'c0',
    'f0', 'f1', 'f2', 'f3', 'f4', 'f7',
    'g0', 'g4',
    'h5', 'h7',
    'l0', 'l1', 'l4', 'l5',
    'n6',
    'u0', 'u3', 'u5',
]


def family_from_mcu(mcu: str) -> str:
    """Map an mcu name (e.g. 'stm32f411') to its product family ('f4')."""
    stem = mcu.removeprefix('stm32')
    for fam in FAMILY_PREFIXES:
        if stem.startswith(fam):
            return fam
    return mcu  # ponytail: no known family (e.g. rebrand parts) -> own bucket


# ---------------------------------------------------------------------------
# Bittype classification
# ---------------------------------------------------------------------------

def classify_bittype(field_name: str) -> str:
    """Classify a 1-bit field name to a C++ bittype."""
    name = field_name.upper()

    prefix = 'common::'

    if name.endswith('RST'):
        return f'{prefix}bit_reset'

    if 'LOCK' in name or name.endswith('LCK'):
        return f'{prefix}bit_locked'

    if 'RDY' in name:
        return f'{prefix}bit_ready'

    if 'BSY' in name:
        return f'{prefix}bit_nready'

    if name.endswith('DIS'):
        return f'{prefix}bit_nenable'

    if name.endswith('EN'):
        return f'{prefix}bit_enable'

    if name.endswith('IE'):
        return f'{prefix}bit_enable'

    if name.endswith('DE'):
        return f'{prefix}bit_enable'

    if name.endswith('PE'):
        return f'{prefix}bit_enable'

    if name.endswith('FE'):
        return f'{prefix}bit_enable'

    if len(name) >= 2 and name[-1] == 'E' and name[-2].isdigit():
        return f'{prefix}bit_enable'

    return 'bool'


def bit_width_to_type(width: int, field_name: str = "") -> str:
    """Map bit width to C++ type, with bittype for 1-bit fields."""
    if width == 1:
        return classify_bittype(field_name)
    elif width <= 8:
        return 'std::uint8_t'
    elif width <= 16:
        return 'std::uint16_t'
    else:
        return 'std::uint32_t'


# ---------------------------------------------------------------------------
# Reserved fields
# ---------------------------------------------------------------------------

def generate_reserved_fields(
    defined_fields: list[Field],
    register_width: int = 32
) -> list[Field]:
    """Generate RESERVED fields for undefined bit ranges."""
    defined_bits = set()
    for f in defined_fields:
        for bit in range(f.lsb, f.msb + 1):
            defined_bits.add(bit)

    reserved_fields = []
    reserved_idx = 0
    in_gap = False
    gap_start = 0

    for bit in range(register_width):
        if bit not in defined_bits:
            if not in_gap:
                in_gap = True
                gap_start = bit
        else:
            if in_gap:
                reserved_fields.append(Field(
                    name=f'RESERVED{reserved_idx}',
                    msb=bit - 1,
                    lsb=gap_start,
                    access='read-only',
                ))
                reserved_idx += 1
                in_gap = False

    if in_gap:
        reserved_fields.append(Field(
            name=f'RESERVED{reserved_idx}',
            msb=register_width - 1,
            lsb=gap_start,
            access='read-only',
        ))

    return reserved_fields


# ---------------------------------------------------------------------------
# Signature computation & deduplication
# ---------------------------------------------------------------------------

def resolve_field_types(reg: Register) -> None:
    """Resolve cpp_type for all fields in a register."""
    for f in reg.fields:
        width = f.msb - f.lsb + 1
        f.cpp_type = bit_width_to_type(width, f.name)


def compute_signature(reg: Register) -> str:
    """Compute MD5 signature for a register based on its layout."""
    parts = [map_access(reg.access)]
    all_fields = reg.fields + generate_reserved_fields(reg.fields)
    for f in sorted(all_fields, key=lambda x: x.lsb):
        width = f.msb - f.lsb + 1
        cpp_type = f.cpp_type if f.cpp_type else bit_width_to_type(
            width, f.name)
        field_access = map_access(f.access) if f.access else ""
        parts.append(f"{f.name}:{f.msb}:{f.lsb}:{field_access}:{cpp_type}")
    raw = "|".join(parts)
    return hashlib.md5(raw.encode()).hexdigest()


# ---------------------------------------------------------------------------
# Peripheral type normalization
# ---------------------------------------------------------------------------

_PERIPH_STRIP_RE = re.compile(
    r'^(.*?)'
    r'[\d]+[A-Z]?$'
)

_PERIPH_GROUP_MAP = {
    'OTG_FS': 'otg_fs',
    'OTG_HS': 'otg_hs',
    'USB_OTG_FS': 'usb_otg_fs',
    'USB_OTG_HS': 'usb_otg_hs',
}


def normalize_periph_type(peripheral: Peripheral) -> str:
    """Determine the normalized peripheral type for grouping."""
    name = peripheral.name

    if name in _PERIPH_GROUP_MAP:
        return _PERIPH_GROUP_MAP[name]

    if peripheral.group_name:
        return peripheral.group_name.lower()

    m = _PERIPH_STRIP_RE.match(name)
    if m and m.group(1):
        return m.group(1).lower()

    return name.lower()


# ---------------------------------------------------------------------------
# Code generation helpers
# ---------------------------------------------------------------------------

def format_address(addr: int) -> str:
    """Format an address with digit separators (e.g., 0x4001'2400)."""
    hex_str = f'{addr:08x}'
    return f"0x{hex_str[:4]}'{hex_str[4:]}"


def format_offset(offset: int) -> str:
    """Format register offset."""
    if offset == 0:
        return '0x0'
    return f'0x{offset:x}'


def field_line(f: Field, register_access: str, is_last: bool) -> str:
    """Generate a groov::field line."""
    width = f.msb - f.lsb + 1
    cpp_type = f.cpp_type if f.cpp_type else bit_width_to_type(
        width, f.name)

    groov_access = map_access(f.access) if f.access else None
    reg_groov_access = map_access(register_access)

    if groov_access and groov_access != reg_groov_access:
        access_str = f', common::access::{groov_access}'
    else:
        access_str = ''

    comma = '' if is_last else ','
    return (f'               groov::field<"{f.name.lower()}", {cpp_type}, '
            f'{f.msb}, {f.lsb}{access_str}>{comma}')


# ---------------------------------------------------------------------------
# Per-MCU processing (parse only, no I/O)
# ---------------------------------------------------------------------------

def collect_mcu(
    svd_path: str,
    global_reg: GlobalRegistry,
    verbose: bool = False,
) -> MCUData:
    """Parse SVD, register templates in global registry, return MCU data."""
    mcu = mcu_name_from_svd(svd_path)
    if verbose:
        print(f"Processing {mcu} from {svd_path}")

    tree = ET.parse(svd_path)
    cpu_el = tree.getroot().find('.//cpu/name')
    cpu_variant = _SVD_CPU_MAP.get(cpu_el.text.strip() if cpu_el is not None else '', '')

    peripherals = parse_svd(svd_path)

    for p in peripherals:
        for reg in p.registers:
            resolve_field_types(reg)
            reg.signature = compute_signature(reg)

    periph_types: dict[str, str] = {
        p.name: normalize_periph_type(p) for p in peripherals
    }

    reg_template_map: dict[tuple[str, str], str] = {}
    total_regs = 0
    new_global = 0

    for p in peripherals:
        ptype = periph_types[p.name]
        for reg in p.registers:
            total_regs += 1
            sig = reg.signature
            label = f'{mcu}::{p.name}'
            was_new = sig not in global_reg.sig_to_template
            global_reg.get_or_create(ptype, reg.name.lower(), sig, reg, label)
            if was_new:
                new_global += 1
            reg_template_map[(p.name, reg.name)] = sig

    type_peripherals: dict[str, list[Peripheral]] = defaultdict(list)
    for p in peripherals:
        type_peripherals[periph_types[p.name]].append(p)

    shared_ns: dict[str, str | None] = {}
    shared_representative: dict[str, Peripheral] = {}
    periph_by_name = {p.name: p for p in peripherals}

    for ptype, p_list in type_peripherals.items():
        ptype_names = {p.name for p in p_list}

        children: dict[str, list[str]] = defaultdict(list)
        for p in p_list:
            if p.derived_from and p.derived_from in ptype_names:
                children[p.derived_from].append(p.name)

        in_group: set[str] = set()
        groups: list[list[Peripheral]] = []
        for p in p_list:
            is_derived = p.derived_from and p.derived_from in ptype_names
            if children.get(p.name) and not is_derived:
                group = [p] + [periph_by_name[c] for c in children[p.name]]
                groups.append(group)
                for member in group:
                    in_group.add(member.name)

        if len(groups) == 1:
            ns = f'{ptype}x'
            shared_representative[ns] = groups[0][0]
            for p in groups[0]:
                shared_ns[p.name] = ns
        elif len(groups) > 1:
            for i, group in enumerate(groups):
                ns = f'{ptype}x' if i == 0 else f'{ptype}x_v{i + 1}'
                shared_representative[ns] = group[0]
                for p in group:
                    shared_ns[p.name] = ns

        for p in p_list:
            if p.name not in in_group:
                shared_ns[p.name] = None

    if verbose:
        print(f"  {len(peripherals)} peripherals, "
              f"{total_regs} registers, "
              f"{new_global} new global templates")

    return MCUData(
        mcu=mcu,
        cpu_variant=cpu_variant,
        peripherals=peripherals,
        periph_types=periph_types,
        type_peripherals=dict(type_peripherals),
        shared_ns=shared_ns,
        shared_representative=shared_representative,
        reg_template_map=reg_template_map,
        total_regs=total_regs,
        new_global_templates=new_global,
    )


# ---------------------------------------------------------------------------
# Code generation: common register headers
# ---------------------------------------------------------------------------

def template_name(tmpl: RegisterTemplate) -> str:
    """Generate the template type alias name."""
    return f'{tmpl.periph_type}_{tmpl.reg_name}_v{tmpl.version}_tt'


def generate_register_header(templates: list[RegisterTemplate]) -> str:
    """Generate a common/registers/<type>.hpp file."""
    lines = []
    lines.append('/* File autogenerated with svd2groov */')
    lines.append('#pragma once')
    lines.append('')
    lines.append('#include <groov/groov.hpp>')
    lines.append('#include "../access.hpp"')
    lines.append('#include "../bittypes.hpp"')
    lines.append('')
    lines.append('namespace erworks::stm32::regs {')

    for tmpl in templates:
        lines.append('')
        tname = template_name(tmpl)
        comment_name = f'{tmpl.periph_type}_{tmpl.reg_name}_v{tmpl.version}'
        lines.append(f'// {comment_name}: {tmpl.reg_name.upper()}')
        lines.append('template <stdx::ct_string name,')
        lines.append('          std::uint32_t   baseaddress,')
        lines.append('          std::uint32_t   offset>')
        lines.append(f'using {tname} =')

        groov_access = map_access(tmpl.access)
        lines.append('  groov::reg<name,')
        lines.append('             std::uint32_t,')
        lines.append('             baseaddress + offset,')
        lines.append(f'             common::access::{groov_access},')

        for i, f in enumerate(tmpl.fields):
            is_last = (i == len(tmpl.fields) - 1)
            line = field_line(f, tmpl.access, is_last)
            if is_last:
                line += '>;'
            lines.append(line)

    lines.append('')
    lines.append('} // namespace erworks::stm32::regs')
    lines.append('')
    return '\n'.join(lines)


def emit_common_registers(output_base: Path, global_reg: GlobalRegistry) -> int:
    """Emit cross-MCU deduplicated register headers to common/registers/.

    Returns the number of files written.
    """
    common_reg_dir = output_base / 'common' / 'registers'
    common_reg_dir.mkdir(parents=True, exist_ok=True)

    type_templates: dict[str, list[RegisterTemplate]] = defaultdict(list)
    for tmpl in global_reg.sig_to_template.values():
        type_templates[tmpl.periph_type].append(tmpl)

    for ptype, templates in sorted(type_templates.items()):
        templates.sort(key=lambda t: (t.reg_name, t.version))
        content = generate_register_header(templates)
        (common_reg_dir / f'{ptype}.hpp').write_text(content)

    return len(type_templates)


# ---------------------------------------------------------------------------
# Code generation: peripheral headers
# ---------------------------------------------------------------------------

def _emit_peripheral_namespace(
    lines: list[str],
    p: Peripheral,
    name_label: str,
    ns_name: str,
    reg_template_map: dict[tuple[str, str], str],
    sig_to_template: dict[str, RegisterTemplate],
    shared: bool,
) -> None:
    """Emit a single peripheral namespace block."""
    lines.append('')
    lines.append(f'namespace {ns_name} {{')

    reg_aliases = []
    for reg in p.registers:
        sig = reg_template_map[(p.name, reg.name)]
        tmpl = sig_to_template[sig]
        tname = template_name(tmpl)
        alias = f'{reg.name.lower()}_tt'
        lines.append(f'  template <stdx::ct_string name,')
        lines.append(f'            std::uint32_t   baseaddress,')
        lines.append(f'            std::uint32_t   offset>')
        lines.append(
            f'  using {alias} = regs::{tname}<name, baseaddress, offset>;')
        reg_aliases.append((alias, reg.name.lower(), reg.offset))

    lines.append('')

    if shared:
        lines.append(
            '  template <stdx::ct_string name, '
            'std::uint32_t baseaddress>')
        lines.append(f'  using {ns_name}_t =')
        lines.append(f'    groov::group<name,')
    else:
        lines.append('  template <std::uint32_t baseaddress>')
        lines.append(f'  using {ns_name}_t =')
        lines.append(f'    groov::group<"{name_label}",')

    lines.append(f'                 groov::mmio_bus<>,')

    for i, (alias, reg_lower, offset) in enumerate(reg_aliases):
        comma = '>;' if i == len(reg_aliases) - 1 else ','
        lines.append(
            f'                 {alias}<"{reg_lower}", baseaddress, '
            f'{format_offset(offset)}>{comma}')

    lines.append('')
    lines.append(f'}} // namespace {ns_name}')


def _peripheral_body_lines(
    peripherals: list[Peripheral],
    reg_template_map: dict[tuple[str, str], str],
    sig_to_template: dict[str, RegisterTemplate],
    shared_ns: dict[str, str | None],
    shared_representative: dict[str, Peripheral],
) -> list[str]:
    """Generate the inner namespace body lines (shared across MCUs)."""
    lines: list[str] = []
    emitted_shared: set[str] = set()

    for p in peripherals:
        ns = shared_ns.get(p.name)
        if ns and ns not in emitted_shared:
            rep = shared_representative[ns]
            _emit_peripheral_namespace(
                lines, rep, ns, ns,
                reg_template_map, sig_to_template,
                shared=True)
            emitted_shared.add(ns)

    for p in peripherals:
        if shared_ns.get(p.name) is None:
            p_lower = p.name.lower()
            _emit_peripheral_namespace(
                lines, p, p_lower, p_lower,
                reg_template_map, sig_to_template,
                shared=False)

    return lines


def generate_peripheral_files(
    mcu: str,
    ptype: str,
    peripherals: list[Peripheral],
    reg_template_map: dict[tuple[str, str], str],
    sig_to_template: dict[str, RegisterTemplate],
    shared_ns: dict[str, str | None],
    shared_representative: dict[str, Peripheral],
    periph_body_reg: dict[str, str],
    common_periph_dir: Path,
) -> str:
    """Generate peripheral wrapper header, emitting shared .inc if needed.

    Returns the wrapper header content.
    """
    body_lines = _peripheral_body_lines(
        peripherals, reg_template_map, sig_to_template,
        shared_ns, shared_representative)
    body = '\n'.join(body_lines)
    body_hash = hashlib.md5(body.encode()).hexdigest()[:12]

    if body_hash not in periph_body_reg:
        inc_filename = f'{ptype}_{body_hash}.inc'
        # ponytail: .inc has no #pragma once — it's the shared body included
        # inside different MCU namespace wrappers, so each inclusion is needed.
        (common_periph_dir / inc_filename).write_text(body + '\n')
        periph_body_reg[body_hash] = inc_filename

    inc_filename = periph_body_reg[body_hash]

    lines = [
        '/* File autogenerated with svd2groov */',
        '#pragma once',
        '#include <groov/groov.hpp>',
        f'#include "../../../common/registers/{ptype}.hpp"',
        f'namespace erworks::stm32::{mcu} {{',
        # ponytail: #include inside namespace — valid C++, wraps shared body
        # in this MCU's namespace without duplicating content per MCU.
        f'#include "../../../common/peripherals/{inc_filename}"',  # NOLINT
        f'}} // namespace erworks::stm32::{mcu}',
        '',
    ]
    return '\n'.join(lines)


# ---------------------------------------------------------------------------
# Code generation: addresses header
# ---------------------------------------------------------------------------

def generate_addresses_header(
    mcu: str,
    peripherals: list[Peripheral],
) -> str:
    """Generate peripherals/addresses.hpp with all base addresses."""
    lines = []
    lines.append('/* File autogenerated with svd2groov */')
    lines.append('#pragma once')
    lines.append('')
    lines.append('#include <cstdint>')
    lines.append('')
    lines.append(f'namespace erworks::stm32::{mcu} {{')

    for p in sorted(peripherals, key=lambda p: p.name.lower()):
        p_lower = p.name.lower()
        p_upper = p.name.upper()
        lines.append(
            f'namespace {p_lower} {{ '
            f'inline constexpr std::uint32_t {p_upper}_BASE = '
            f'{format_address(p.base_address)}; '
            f'}} // namespace {p_lower}')

    lines.append('')
    lines.append(f'}} // namespace erworks::stm32::{mcu}')
    lines.append('')
    return '\n'.join(lines)


# ---------------------------------------------------------------------------
# Code generation: MCU aggregate
# ---------------------------------------------------------------------------

def generate_aggregate(
    mcu: str,
    cpu_variant: str,
    peripherals: list[Peripheral],
    periph_types: dict[str, str],
    type_peripherals: dict[str, list[Peripheral]],
    shared_ns: dict[str, str | None],
) -> str:
    """Generate the <mcu>/<mcu>.hpp aggregate header."""
    lines = []
    lines.append(f'/* File autogenerated with svd2groov for {mcu} */')
    lines.append('#pragma once')
    lines.append('')

    for ptype in sorted(type_peripherals.keys()):
        lines.append(f'#include "peripherals/{ptype}.hpp"')
    lines.append('')
    lines.append('#include "peripherals/addresses.hpp"')
    if cpu_variant:
        lines.append(f'#include "../../common/core/{cpu_variant}.hpp"')
    lines.append('')
    lines.append('namespace erworks::stm32 {')

    for p in sorted(peripherals, key=lambda p: p.name.lower()):
        p_lower = p.name.lower()
        p_upper = p.name.upper()
        ns = shared_ns.get(p.name)

        lines.append('')
        if ns:
            lines.append(
                f'constexpr auto {p_lower} = '
                f'{mcu}::{ns}::{ns}_t<'
                f'"{p_lower}",{mcu}::{p_lower}::{p_upper}_BASE>{{}};')
        else:
            lines.append(
                f'constexpr auto {p_lower} = '
                f'{mcu}::{p_lower}::{p_lower}_t<'
                f'{mcu}::{p_lower}::{p_upper}_BASE>{{}};')

    lines.append('')
    lines.append('} // namespace erworks::stm32')
    lines.append('')
    return '\n'.join(lines)


# ---------------------------------------------------------------------------
# MCU file emission
# ---------------------------------------------------------------------------

def emit_mcu_files(
    mcu_data: MCUData,
    output_base: Path,
    global_reg: GlobalRegistry,
    periph_body_reg: dict[str, str],
    verbose: bool = False,
) -> None:
    """Emit per-MCU peripheral headers, addresses, and aggregate."""
    mcu = mcu_data.mcu
    mcu_dir = output_base / family_from_mcu(mcu) / mcu

    # Remove stale per-MCU register dir (superseded by common/registers/)
    old_reg_dir = mcu_dir / 'registers'
    if old_reg_dir.exists():
        shutil.rmtree(old_reg_dir)

    periph_dir = mcu_dir / 'peripherals'
    periph_dir.mkdir(parents=True, exist_ok=True)

    common_periph_dir = output_base / 'common' / 'peripherals'
    common_periph_dir.mkdir(parents=True, exist_ok=True)

    for ptype, p_list in sorted(mcu_data.type_peripherals.items()):
        content = generate_peripheral_files(
            mcu, ptype, p_list,
            mcu_data.reg_template_map,
            global_reg.sig_to_template,
            mcu_data.shared_ns,
            mcu_data.shared_representative,
            periph_body_reg,
            common_periph_dir,
        )
        (periph_dir / f'{ptype}.hpp').write_text(content)

    addresses = generate_addresses_header(mcu, mcu_data.peripherals)
    (periph_dir / 'addresses.hpp').write_text(addresses)

    aggregate = generate_aggregate(
        mcu, mcu_data.cpu_variant, mcu_data.peripherals, mcu_data.periph_types,
        mcu_data.type_peripherals, mcu_data.shared_ns)
    (mcu_dir / f'{mcu}.hpp').write_text(aggregate)

    if verbose:
        print(f"  emitted {len(mcu_data.type_peripherals)} peripheral files")


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def list_peripherals(svd_path: str) -> list[str]:
    """List all peripheral names from an SVD file (lowercase, sorted)."""
    peripherals = parse_svd(svd_path)
    return sorted(p.name.lower() for p in peripherals)


def main():
    parser = argparse.ArgumentParser(
        description='Generate GROOV C++ headers from STM32 SVD files'
    )
    parser.add_argument(
        'svd_files',
        nargs='+',
        help='Input SVD file(s)'
    )
    parser.add_argument(
        '-o', '--output',
        required=True,
        help='Output base directory (e.g. include/stm32/)'
    )
    parser.add_argument(
        '--verbose',
        action='store_true',
        help='Print per-file progress'
    )
    parser.add_argument(
        '--stats',
        action='store_true',
        help='Print deduplication statistics at end'
    )
    parser.add_argument(
        '--list-peripherals',
        action='store_true',
        help='Print peripheral names (one per line) and exit'
    )

    args = parser.parse_args()

    if args.list_peripherals:
        for svd_path in args.svd_files:
            for name in list_peripherals(svd_path):
                print(name)
        return

    output_base = Path(args.output)
    global_reg = GlobalRegistry()
    periph_body_reg: dict[str, str] = {}  # body_hash -> .inc filename

    # Phase 1: parse all MCUs, build global register registry
    all_mcu_data: list[MCUData] = []
    for svd_path in args.svd_files:
        mcu_data = collect_mcu(svd_path, global_reg, verbose=args.verbose)
        all_mcu_data.append(mcu_data)

    # Phase 2: emit shared register files
    n_reg_files = emit_common_registers(output_base, global_reg)
    if args.verbose:
        print(f"Emitted {n_reg_files} common register files")

    # Phase 3: emit per-MCU peripheral, address, and aggregate files
    for mcu_data in all_mcu_data:
        emit_mcu_files(
            mcu_data, output_base, global_reg,
            periph_body_reg, verbose=args.verbose)

    # Phase 4: mcu -> family manifest, read by meson.build at configure time
    manifest_lines = [
        f'{d.mcu}={family_from_mcu(d.mcu)}'
        for d in sorted(all_mcu_data, key=lambda d: d.mcu)
    ]
    (output_base / 'mcu_family.txt').write_text('\n'.join(manifest_lines) + '\n')

    if args.stats:
        total_regs = sum(d.total_regs for d in all_mcu_data)
        total_new = sum(d.new_global_templates for d in all_mcu_data)
        total_global = len(global_reg.sig_to_template)
        n_mcu = len(all_mcu_data)
        n_periph_inc = len(periph_body_reg)

        print(f"\n--- Statistics ---")
        print(f"MCUs processed:          {n_mcu}")
        print(f"Total registers:         {total_regs}")
        print(f"Global unique templates: {total_global}")
        print(f"Register dedup ratio:    "
              f"{(1 - total_global / total_regs) * 100:.1f}% "
              f"({total_regs - total_global} duplicates eliminated)")
        print(f"Common register files:   {n_reg_files}")
        print(f"Common peripheral .inc:  {n_periph_inc}")
        print(f"Per-MCU periph wrappers: "
              f"{sum(len(d.type_peripherals) for d in all_mcu_data)}")


if __name__ == '__main__':
    main()
