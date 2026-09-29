#!/usr/bin/env python3
"""
SVD to GROOV C++ header generator.

Parses STM32 SVD files and generates GROOV-compatible C++ headers
with per-MCU register deduplication and bittype classification.
"""

import argparse
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
    name: str
    msb: int
    lsb: int
    access: str | None = None  # None means inherit from register
    cpp_type: str = ""         # Resolved C++ type (set after classification)


@dataclass
class Register:
    name: str
    offset: int
    access: str
    fields: list[Field] = field(default_factory=list)
    signature: str = ""


@dataclass
class Interrupt:
    name: str
    value: int


@dataclass
class Peripheral:
    name: str
    base_address: int
    group_name: str = ""
    registers: list[Register] = field(default_factory=list)
    interrupts: list[Interrupt] = field(default_factory=list)
    derived_from: str | None = None


@dataclass
class RegisterTemplate:
    periph_type: str        # Normalized peripheral type (e.g. "tim")
    reg_name: str           # Register name (e.g. "cr1")
    version: int            # Per (periph_type, reg_name) version number
    access: str             # Register-level access
    fields: list[Field]     # All fields (including reserved)
    used_by: list[str] = field(default_factory=list)  # "mcu::PERIPH" labels
    signature: str = ""


@dataclass
class RegisterRegistry:
    """Per-MCU register template registry for deduplication."""
    sig_to_template: dict[str, RegisterTemplate] = field(default_factory=dict)
    version_counters: dict[tuple[str, str], int] = field(
        default_factory=lambda: defaultdict(int))

    def get_or_create(self, ptype: str, reg_name: str, sig: str,
                       reg: 'Register', label: str) -> None:
        if sig not in self.sig_to_template:
            self.version_counters[(ptype, reg_name)] += 1
            ver = self.version_counters[(ptype, reg_name)]
            all_fields = [
                Field(f.name, f.msb, f.lsb, f.access, f.cpp_type)
                for f in reg.fields
            ]
            for rf in generate_reserved_fields(reg.fields):
                rf.cpp_type = bit_width_to_type(rf.msb - rf.lsb + 1, rf.name)
                all_fields.append(rf)
            all_fields.sort(key=lambda f: f.msb, reverse=True)
            self.sig_to_template[sig] = RegisterTemplate(
                periph_type=ptype, reg_name=reg_name, version=ver,
                access=reg.access, fields=all_fields, used_by=[label],
                signature=sig)
        else:
            used = self.sig_to_template[sig].used_by
            if label not in used:
                used.append(label)


_SVD_CPU_MAP: dict[str, str] = {
    'CM0': 'cm0', 'CM0+': 'cm0p', 'CM3': 'cm3', 'CM4': 'cm4', 'CM7': 'cm7',
    'CM23': 'cm0p', 'CM33': 'cm33', 'CM35P': 'cm33', 'CM55': 'cm55',
    'CM85': 'cm55',
}


@dataclass
class MCUData:
    """Per-MCU processing results (no I/O)."""
    mcu: str
    cpu_variant: str
    peripherals: list[Peripheral]
    periph_types: dict[str, str]
    type_peripherals: dict[str, list[Peripheral]]
    shared_ns: dict[str, str | None]
    shared_representative: dict[str, Peripheral]
    reg_template_map: dict[tuple[str, str], str]  # (periph, reg) -> sig
    registry: RegisterRegistry
    total_regs: int


# ---------------------------------------------------------------------------
# SVD parsing
# ---------------------------------------------------------------------------


def parse_int(value: str | None) -> int:
    if value is None:
        return 0
    value = value.strip()
    if value.startswith(('0x', '0X')):
        return int(value, 16)
    return int(value)


def map_access(svd_access: str | None) -> str:
    return {
        'read-write': 'rw', 'read-only': 'ro', 'write-only': 'wo',
        'writeOnce': 'wo', 'read-writeOnce': 'rw',
    }.get(svd_access, 'rw')


def parse_fields(register_elem: ET.Element) -> list[Field]:
    fields = []
    fields_elem = register_elem.find('fields')
    if fields_elem is None:
        return fields

    for field_elem in fields_elem.findall('field'):
        name_elem = field_elem.find('name')
        if name_elem is None or name_elem.text is None:
            continue
        name = name_elem.text

        bit_offset_elem = field_elem.find('bitOffset')
        bit_width_elem = field_elem.find('bitWidth')

        if bit_offset_elem is not None and bit_width_elem is not None:
            lsb = parse_int(bit_offset_elem.text)
            msb = lsb + parse_int(bit_width_elem.text) - 1
        else:
            bit_range_elem = field_elem.find('bitRange')
            if bit_range_elem is not None and bit_range_elem.text:
                match = re.match(r'\[(\d+):(\d+)\]', bit_range_elem.text)
                if not match:
                    continue
                msb, lsb = int(match.group(1)), int(match.group(2))
            else:
                lsb_elem = field_elem.find('lsb')
                msb_elem = field_elem.find('msb')
                if lsb_elem is None or msb_elem is None:
                    continue
                lsb, msb = parse_int(lsb_elem.text), parse_int(msb_elem.text)

        access_elem = field_elem.find('access')
        access = access_elem.text if access_elem is not None else None
        fields.append(Field(name=name, msb=msb, lsb=lsb, access=access))

    return fields


def parse_register(register_elem: ET.Element) -> Register:
    name = register_elem.find('name').text
    offset = parse_int(register_elem.find('addressOffset').text)
    access_elem = register_elem.find('access')
    access = access_elem.text if access_elem is not None else 'read-write'
    return Register(name=name, offset=offset, access=access,
                     fields=parse_fields(register_elem))


def parse_interrupts(node: ET.Element) -> list[Interrupt]:
    """A peripheral's <interrupt> elements are direct children."""
    irqs = []
    for irq_elem in node.findall('interrupt'):
        name_elem = irq_elem.find('name')
        val_elem = irq_elem.find('value')
        if name_elem is None or val_elem is None:
            continue
        irqs.append(Interrupt(name=name_elem.text, value=parse_int(val_elem.text)))
    return irqs


def parse_peripheral(peripheral_elem: ET.Element,
                      all_peripherals: dict[str, Peripheral]) -> Peripheral:
    name = peripheral_elem.find('name').text
    base_address = parse_int(peripheral_elem.find('baseAddress').text)
    derived_from = peripheral_elem.get('derivedFrom')

    group_elem = peripheral_elem.find('groupName')
    group_name = group_elem.text if group_elem is not None else ""

    source = all_peripherals.get(derived_from) if derived_from else None
    registers = []
    if source is not None:
        for reg in source.registers:
            registers.append(Register(
                name=reg.name, offset=reg.offset, access=reg.access,
                fields=[Field(f.name, f.msb, f.lsb, f.access) for f in reg.fields]))
        if not group_name:
            group_name = source.group_name
    else:
        registers_elem = peripheral_elem.find('registers')
        if registers_elem is not None:
            for register_elem in registers_elem.findall('register'):
                registers.append(parse_register(register_elem))

    # Interrupts differ per instance even when derived (e.g. USART2 from
    # USART1), so only fall back to the source's when this one has none.
    interrupts = parse_interrupts(peripheral_elem)
    if not interrupts and source is not None:
        interrupts = source.interrupts

    return Peripheral(name=name, base_address=base_address, group_name=group_name,
                       registers=registers, interrupts=interrupts,
                       derived_from=derived_from)


def parse_svd(filename: str) -> list[Peripheral]:
    root = ET.parse(filename).getroot()

    peripherals: dict[str, Peripheral] = {}
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
    root = ET.parse(svd_path).getroot()
    name_elem = root.find('name')
    if name_elem is not None and name_elem.text:
        return name_elem.text.strip().lower()
    return Path(svd_path).stem.lower()


# Longest/most-specific prefix first: 'wba' before 'wb'.
FAMILY_PREFIXES = [
    'wba', 'wb', 'wl', 'c0', 'f0', 'f1', 'f2', 'f3', 'f4', 'f7',
    'g0', 'g4', 'h5', 'h7', 'l0', 'l1', 'l4', 'l5', 'n6', 'u0', 'u3', 'u5',
]


def family_from_mcu(mcu: str) -> str:
    stem = mcu.removeprefix('stm32')
    for fam in FAMILY_PREFIXES:
        if stem.startswith(fam):
            return fam
    return mcu  # no known family (e.g. rebrand parts) -> own bucket


# ---------------------------------------------------------------------------
# Bittype classification
# ---------------------------------------------------------------------------


def classify_bittype(field_name: str) -> str:
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
    if name.endswith(('EN', 'IE', 'DE', 'PE', 'FE')):
        return f'{prefix}bit_enable'
    if len(name) >= 2 and name[-1] == 'E' and name[-2].isdigit():
        return f'{prefix}bit_enable'
    return 'bool'


def bit_width_to_type(width: int, field_name: str = "") -> str:
    if width == 1:
        return classify_bittype(field_name)
    if width <= 8:
        return 'std::uint8_t'
    if width <= 16:
        return 'std::uint16_t'
    return 'std::uint32_t'


# ---------------------------------------------------------------------------
# Reserved fields
# ---------------------------------------------------------------------------


def generate_reserved_fields(defined_fields: list[Field],
                              register_width: int = 32) -> list[Field]:
    defined_bits = set()
    for f in defined_fields:
        defined_bits.update(range(f.lsb, f.msb + 1))

    reserved_fields = []
    idx = 0
    in_gap = False
    gap_start = 0

    for bit in range(register_width):
        if bit not in defined_bits:
            if not in_gap:
                in_gap, gap_start = True, bit
        elif in_gap:
            reserved_fields.append(Field(f'RESERVED{idx}', bit - 1, gap_start,
                                          access='read-only'))
            idx += 1
            in_gap = False

    if in_gap:
        reserved_fields.append(Field(f'RESERVED{idx}', register_width - 1,
                                      gap_start, access='read-only'))
    return reserved_fields


# ---------------------------------------------------------------------------
# Signature computation & deduplication
# ---------------------------------------------------------------------------


def resolve_field_types(reg: Register) -> None:
    for f in reg.fields:
        f.cpp_type = bit_width_to_type(f.msb - f.lsb + 1, f.name)


def compute_signature(reg: Register) -> str:
    """In-process dedup key only, so a plain joined string stands in for a hash."""
    parts = [map_access(reg.access)]
    all_fields = reg.fields + generate_reserved_fields(reg.fields)
    for f in sorted(all_fields, key=lambda x: x.lsb):
        width = f.msb - f.lsb + 1
        cpp_type = f.cpp_type or bit_width_to_type(width, f.name)
        field_access = map_access(f.access) if f.access else ""
        parts.append(f"{f.name}:{f.msb}:{f.lsb}:{field_access}:{cpp_type}")
    return "|".join(parts)


# ---------------------------------------------------------------------------
# Peripheral type normalization
# ---------------------------------------------------------------------------

_PERIPH_STRIP_RE = re.compile(r'^(.*?)[0-9]+[A-Z]?$')

_PERIPH_GROUP_MAP = {
    'OTG_FS': 'otg_fs', 'OTG_HS': 'otg_hs',
    'USB_OTG_FS': 'usb_otg_fs', 'USB_OTG_HS': 'usb_otg_hs',
}


def normalize_periph_type(peripheral: Peripheral) -> str:
    if peripheral.name in _PERIPH_GROUP_MAP:
        return _PERIPH_GROUP_MAP[peripheral.name]
    if peripheral.group_name:
        return peripheral.group_name.lower()
    m = _PERIPH_STRIP_RE.match(peripheral.name)
    if m and m.group(1):
        return m.group(1).lower()
    return peripheral.name.lower()


# ---------------------------------------------------------------------------
# Code generation helpers
# ---------------------------------------------------------------------------


def format_address(addr: int) -> str:
    hex_str = f'{addr:08x}'
    return f"0x{hex_str[:4]}'{hex_str[4:]}"


def format_offset(offset: int) -> str:
    return '0x0' if offset == 0 else f'0x{offset:x}'


def field_line(f: Field, register_access: str, is_last: bool) -> str:
    width = f.msb - f.lsb + 1
    cpp_type = f.cpp_type or bit_width_to_type(width, f.name)

    access_str = ''
    if f.access:
        ga = map_access(f.access)
        if ga != map_access(register_access):
            access_str = f', common::access::{ga}'

    comma = '' if is_last else ','
    return (f'{" " * 15}groov::field<"{f.name.lower()}", {cpp_type}, '
            f'{f.msb}, {f.lsb}{access_str}>{comma}')


# ---------------------------------------------------------------------------
# Per-MCU processing (parse only, no I/O)
# ---------------------------------------------------------------------------


def collect_mcu(svd_path: str, verbose: bool = False) -> MCUData:
    registry = RegisterRegistry()
    mcu = mcu_name_from_svd(svd_path)
    if verbose:
        print(f"Processing {mcu} from {svd_path}")

    root = ET.parse(svd_path).getroot()
    cpu_el = root.find('./cpu/name')
    cpu_variant = _SVD_CPU_MAP.get(cpu_el.text.strip() if cpu_el is not None and cpu_el.text else '', '')

    peripherals = parse_svd(svd_path)

    for p in peripherals:
        for reg in p.registers:
            resolve_field_types(reg)
            reg.signature = compute_signature(reg)

    periph_types = {p.name: normalize_periph_type(p) for p in peripherals}

    reg_template_map: dict[tuple[str, str], str] = {}
    total_regs = 0
    for p in peripherals:
        ptype = periph_types[p.name]
        for reg in p.registers:
            total_regs += 1
            label = f'{mcu}::{p.name}'
            registry.get_or_create(ptype, reg.name.lower(), reg.signature, reg, label)
            reg_template_map[(p.name, reg.name)] = reg.signature

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
            is_derived = bool(p.derived_from and p.derived_from in ptype_names)
            if children.get(p.name) and not is_derived:
                group = [p] + [periph_by_name[c] for c in children[p.name]]
                groups.append(group)
                in_group.update(member.name for member in group)

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
        print(f"  {len(peripherals)} peripherals, {total_regs} registers, "
              f"{len(registry.sig_to_template)} unique templates")

    return MCUData(mcu=mcu, cpu_variant=cpu_variant, peripherals=peripherals,
                    periph_types=periph_types, type_peripherals=dict(type_peripherals),
                    shared_ns=shared_ns, shared_representative=shared_representative,
                    reg_template_map=reg_template_map, registry=registry,
                    total_regs=total_regs)


# ---------------------------------------------------------------------------
# Code generation: register templates (inlined into peripheral headers)
# ---------------------------------------------------------------------------


def template_stem(t: RegisterTemplate) -> str:
    return f'{t.periph_type}_{t.reg_name}_v{t.version}'


def template_name(t: RegisterTemplate) -> str:
    return f'{template_stem(t)}_tt'


def register_template_lines(templates: list[RegisterTemplate]) -> list[str]:
    lines = ['namespace regs {']

    for tmpl in templates:
        lines.append('')
        stem = template_stem(tmpl)
        tname = f'{stem}_tt'
        lines.append(f'// {stem}: {tmpl.reg_name.upper()}')
        lines.append('template <stdx::ct_string name,')
        lines.append(f'{" " * 10}std::uint32_t   baseaddress,')
        lines.append(f'{" " * 10}std::uint32_t   offset>')
        lines.append(f'using {tname} =')

        lines.append('  groov::reg<name,')
        lines.append(f'{" " * 13}std::uint32_t,')
        lines.append(f'{" " * 13}baseaddress + offset,')
        lines.append(f'{" " * 13}common::access::{map_access(tmpl.access)},')

        for i, f in enumerate(tmpl.fields):
            is_last = i == len(tmpl.fields) - 1
            line = field_line(f, tmpl.access, is_last)
            if is_last:
                line += '>;'
            lines.append(line)

    lines.append('')
    lines.append('} // namespace regs')
    return lines


# ---------------------------------------------------------------------------
# Code generation: peripheral headers
# ---------------------------------------------------------------------------


def _emit_peripheral_namespace(
    lines: list[str], p: Peripheral, name_label: str, ns_name: str,
    reg_template_map: dict[tuple[str, str], str],
    sig_to_template: dict[str, RegisterTemplate], shared: bool,
) -> None:
    lines.append('')
    lines.append(f'namespace {ns_name} {{')

    reg_aliases = []
    for reg in p.registers:
        sig = reg_template_map[(p.name, reg.name)]
        tmpl = sig_to_template[sig]
        tname = template_name(tmpl)
        alias = f'{reg.name.lower()}_tt'
        lines.append('  template <stdx::ct_string name,')
        lines.append(f'{" " * 12}std::uint32_t   baseaddress,')
        lines.append(f'{" " * 12}std::uint32_t   offset>')
        lines.append(f'  using {alias} = regs::{tname}<name, baseaddress, offset>;')
        reg_aliases.append((alias, reg.name.lower(), reg.offset))

    lines.append('')

    if shared:
        lines.append('  template <stdx::ct_string name, std::uint32_t baseaddress>')
        lines.append(f'  using {ns_name}_t =')
        lines.append('    groov::group<name,')
    else:
        lines.append('  template <std::uint32_t baseaddress>')
        lines.append(f'  using {ns_name}_t =')
        lines.append(f'    groov::group<"{name_label}",')

    lines.append(f'{" " * 17}groov::mmio_bus<>,')

    for i, (alias, reg_lower, offset) in enumerate(reg_aliases):
        comma = '>;' if i == len(reg_aliases) - 1 else ','
        lines.append(f'{" " * 17}{alias}<"{reg_lower}", baseaddress, '
                      f'{format_offset(offset)}>{comma}')

    lines.append('')
    lines.append(f'}} // namespace {ns_name}')


def _peripheral_body_lines(
    peripherals: list[Peripheral], reg_template_map: dict[tuple[str, str], str],
    sig_to_template: dict[str, RegisterTemplate],
    shared_ns: dict[str, str | None], shared_representative: dict[str, Peripheral],
) -> list[str]:
    lines: list[str] = []
    emitted_shared: set[str] = set()

    for p in peripherals:
        ns = shared_ns.get(p.name)
        if ns and ns not in emitted_shared:
            _emit_peripheral_namespace(lines, shared_representative[ns], ns, ns,
                                        reg_template_map, sig_to_template, shared=True)
            emitted_shared.add(ns)

    for p in peripherals:
        if shared_ns.get(p.name) is None:
            p_lower = p.name.lower()
            _emit_peripheral_namespace(lines, p, p_lower, p_lower, reg_template_map,
                                        sig_to_template, shared=False)

    return lines


def generate_peripheral_file(
    mcu: str, ptype: str, peripherals: list[Peripheral],
    reg_template_map: dict[tuple[str, str], str],
    sig_to_template: dict[str, RegisterTemplate],
    shared_ns: dict[str, str | None], shared_representative: dict[str, Peripheral],
) -> str:
    """Per-MCU <family>/<mcu>/<ptype>.hpp; nothing is shared between MCUs."""
    templates = sorted(
        (t for t in sig_to_template.values() if t.periph_type == ptype),
        key=lambda t: (t.reg_name, t.version))

    lines = [
        '/* File autogenerated with svd2groov */',
        '#pragma once',
        '#include <groov/groov.hpp>',
        '#include "../../common/access.hpp"',
        '#include "../../common/bittypes.hpp"',
        f'namespace erworks::stm32::{mcu} {{',
        *register_template_lines(templates),
        *_peripheral_body_lines(peripherals, reg_template_map, sig_to_template,
                                 shared_ns, shared_representative),
        f'}} // namespace erworks::stm32::{mcu}',
        '',
    ]
    return '\n'.join(lines)


# ---------------------------------------------------------------------------
# Code generation: addresses header
# ---------------------------------------------------------------------------


def generate_addresses_header(mcu: str, peripherals: list[Peripheral]) -> str:
    lines = [
        '/* File autogenerated with svd2groov */',
        '#pragma once',
        '',
        '#include <cstdint>',
        '',
        f'namespace erworks::stm32::{mcu} {{',
    ]

    for p in sorted(peripherals, key=lambda p: p.name.lower()):
        p_lower, p_upper = p.name.lower(), p.name.upper()
        lines.append(
            f'namespace {p_lower} {{ inline constexpr std::uint32_t {p_upper}_BASE = '
            f'{format_address(p.base_address)}; }} // namespace {p_lower}')

    lines.append('')
    lines.append(f'}} // namespace erworks::stm32::{mcu}')
    lines.append('')
    return '\n'.join(lines)


# ---------------------------------------------------------------------------
# Code generation: MCU aggregate
# ---------------------------------------------------------------------------


def generate_aggregate(
    mcu: str, cpu_variant: str, peripherals: list[Peripheral],
    type_peripherals: dict[str, list[Peripheral]], shared_ns: dict[str, str | None],
) -> str:
    lines = [f'/* File autogenerated with svd2groov for {mcu} */', '#pragma once', '']

    for ptype in sorted(type_peripherals):
        lines.append(f'#include "{mcu}/{ptype}.hpp"')
    lines.append('')
    lines.append(f'#include "{mcu}/addresses.hpp"')
    if cpu_variant:
        lines.append(f'#include "../core/{cpu_variant}.hpp"')
    lines.append('')
    lines.append('namespace erworks::stm32 {')

    for p in sorted(peripherals, key=lambda p: p.name.lower()):
        p_lower, p_upper = p.name.lower(), p.name.upper()
        ns = shared_ns.get(p.name)

        lines.append('')
        if ns:
            lines.append(f'constexpr auto {p_lower} = {mcu}::{ns}::{ns}_t<'
                          f'"{p_lower}",{mcu}::{p_lower}::{p_upper}_BASE>{{}};')
        else:
            lines.append(f'constexpr auto {p_lower} = {mcu}::{p_lower}::{p_lower}_t<'
                          f'{mcu}::{p_lower}::{p_upper}_BASE>{{}};')

    lines.append('')
    lines.append('} // namespace erworks::stm32')
    lines.append('')
    return '\n'.join(lines)


# ---------------------------------------------------------------------------
# MCU file emission
# ---------------------------------------------------------------------------


# Device-wide interrupt list: peripherals can share an IRQ line (e.g. an EXTI
# range spans multiple EXTIx entries), so dedupe by vector position, keeping
# the name first seen in document order.
def collect_interrupts(peripherals: list[Peripheral]) -> list[Interrupt]:
    by_value: dict[int, str] = {}
    for p in peripherals:
        for irq in p.interrupts:
            by_value.setdefault(irq.value, irq.name)
    return [Interrupt(name, value) for value, name in sorted(by_value.items())]


# Generates the .isr_vector.device table consumed by src/startup.cpp's linker
# script (KEEP(*(.isr_vector.device)), directly after the core vector table).
# Each handler forwards to _default() rather than aliasing it, since
# GCC/Clang's alias attribute requires the target to be defined in the same
# translation unit, and _default() lives in startup.cpp.
def generate_irq_vector_file(mcu: str, irqs: list[Interrupt]) -> str:
    if not irqs:
        return ''

    max_value = max(irq.value for irq in irqs)
    by_value = {irq.value: irq.name for irq in irqs}

    lines = [
        f'/* File autogenerated with svd2groov for {mcu} */',
        '#include <cstdint>',
        '',
        'extern "C" void _default();',
        '',
        '// NOLINTBEGIN(*-identifier-naming)',
    ]

    for value in sorted(by_value):
        name = by_value[value]
        lines.append(f'extern "C" __attribute__((weak)) void {name}_IRQHandler() '
                      '{ _default(); }')

    lines.append('')
    lines.append('extern "C" const volatile std::uintptr_t device_vector_table[]')
    lines.append('  __attribute__((section(".isr_vector.device"))) = {')

    for v in range(max_value + 1):
        comma = '' if v == max_value else ','
        if v in by_value:
            lines.append(f'    reinterpret_cast<std::uintptr_t>(&{by_value[v]}_IRQHandler)'
                          f'{comma} // {v}: {by_value[v]}')
        else:
            lines.append(f'    0{comma} // {v}: Reserved')

    lines.append('};')
    lines.append('// NOLINTEND(*-identifier-naming)')
    lines.append('')
    return '\n'.join(lines)


def emit_mcu_files(mcu_data: MCUData, output_base: Path, verbose: bool = False) -> None:
    mcu = mcu_data.mcu
    family_dir = output_base / family_from_mcu(mcu)
    mcu_dir = family_dir / mcu

    # Fully regenerated, nothing hand-written: wipe stale layout.
    if mcu_dir.exists():
        shutil.rmtree(mcu_dir)
    mcu_dir.mkdir(parents=True, exist_ok=True)

    for ptype, p_list in mcu_data.type_peripherals.items():
        content = generate_peripheral_file(
            mcu, ptype, p_list, mcu_data.reg_template_map,
            mcu_data.registry.sig_to_template, mcu_data.shared_ns,
            mcu_data.shared_representative)
        (mcu_dir / f'{ptype}.hpp').write_text(content)

    (mcu_dir / 'addresses.hpp').write_text(
        generate_addresses_header(mcu, mcu_data.peripherals))

    irq_vector = generate_irq_vector_file(mcu, collect_interrupts(mcu_data.peripherals))
    if irq_vector:
        (mcu_dir / 'irq_vector.cpp').write_text(irq_vector)

    (family_dir / f'{mcu}.hpp').write_text(generate_aggregate(
        mcu, mcu_data.cpu_variant, mcu_data.peripherals,
        mcu_data.type_peripherals, mcu_data.shared_ns))

    if verbose:
        print(f"  emitted {len(mcu_data.type_peripherals)} peripheral files")


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------


def list_peripherals(svd_path: str) -> None:
    for name in sorted(p.name.lower() for p in parse_svd(svd_path)):
        print(name)


def list_interrupts(svd_path: str) -> None:
    for irq in collect_interrupts(parse_svd(svd_path)):
        print(f'{irq.value} {irq.name}')


def main() -> int:
    parser = argparse.ArgumentParser(
        description='Generate GROOV C++ headers from STM32 SVD files')
    parser.add_argument('svd_files', nargs='+', help='Input SVD file(s)')
    parser.add_argument('-o', '--output', help='Output base directory (e.g. include/stm32/)')
    parser.add_argument('--verbose', action='store_true', help='Print per-file progress')
    parser.add_argument('--stats', action='store_true',
                         help='Print deduplication statistics at end')
    parser.add_argument('--list-peripherals', action='store_true',
                         help='Print peripheral names (one per line) and exit')
    parser.add_argument('--list-interrupts', action='store_true',
                         help='Print "<value> <name>" for each interrupt, '
                              'sorted by value, and exit')
    args = parser.parse_args()

    if args.list_peripherals:
        for svd_path in args.svd_files:
            list_peripherals(svd_path)
        return 0

    if args.list_interrupts:
        for svd_path in args.svd_files:
            list_interrupts(svd_path)
        return 0

    if not args.output:
        parser.error("the following arguments are required: -o/--output")
    output_base = Path(args.output)

    # Drop the old cross-MCU shared trees (registers now inlined per-MCU).
    for sub in ('registers', 'peripherals'):
        stale = output_base / 'common' / sub
        if stale.exists():
            shutil.rmtree(stale)

    all_mcu_data = [collect_mcu(svd_path, verbose=args.verbose)
                     for svd_path in args.svd_files]
    for mcu_data in all_mcu_data:
        emit_mcu_files(mcu_data, output_base, verbose=args.verbose)

    if args.stats:
        total_regs = sum(d.total_regs for d in all_mcu_data)
        total_tmpl = sum(len(d.registry.sig_to_template) for d in all_mcu_data)

        print("\n--- Statistics ---")
        print(f"MCUs processed:          {len(all_mcu_data)}")
        print(f"Total registers:         {total_regs}")
        print(f"Per-MCU unique templates:{total_tmpl}")
        if total_regs:
            ratio = (1 - total_tmpl / total_regs) * 100
            print(f"Register dedup ratio:    {ratio:.1f}% "
                  f"({total_regs - total_tmpl} duplicates eliminated)")
        print(f"Per-MCU periph headers:  "
              f"{sum(len(d.type_peripherals) for d in all_mcu_data)}")

    return 0


if __name__ == '__main__':
    raise SystemExit(main())
