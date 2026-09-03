#!/usr/bin/env python3
"""
CMSIS core_cm*.h to GROOV C++ header generator.

Parses ARM CMSIS core peripheral struct layouts and bit-field macros, then
emits groov register/group templates into common/core/<variant>/.

Usage:
  cmsis2groov.py -o include/stm32/ \\
      --cm0    path/to/core_cm0.h    \\
      --cm0p   path/to/core_cm0plus.h \\
      --cm3    path/to/core_cm3.h    \\
      --cm4    path/to/core_cm4.h    \\
      --cm7    path/to/core_cm7.h    \\
      --cm33   path/to/core_cm33.h   \\
      --cm55   path/to/core_cm55.h
"""

import argparse
import re
from dataclasses import dataclass, field
from pathlib import Path


# ---------------------------------------------------------------------------
# Peripheral → core variant availability table
# (SVD fpuPresent/mpuPresent are unreliable; use architecture spec instead)
# ---------------------------------------------------------------------------

# fmt: off
CORE_PERIPHERALS: dict[str, list[str]] = {
    'cm0':   ['systick', 'scb'],
    'cm0p':  ['systick', 'scb', 'mpu'],
    'cm3':   ['systick', 'scb', 'mpu', 'coredebug', 'dwt', 'itm'],
    'cm4':   ['systick', 'scb', 'mpu', 'fpu', 'coredebug', 'dwt', 'itm'],
    'cm7':   ['systick', 'scb', 'mpu', 'fpu', 'coredebug', 'dwt', 'itm'],
    'cm33':  ['systick', 'scb', 'mpu', 'fpu', 'coredebug', 'dwt', 'itm', 'sau', 'dcb'],
    'cm55':  ['systick', 'scb', 'mpu', 'fpu', 'coredebug', 'dwt', 'itm', 'sau', 'dcb'],
}

# SVD <cpu><name> → variant key used above
SVD_CPU_MAP: dict[str, str] = {
    'CM0':   'cm0',
    'CM0+':  'cm0p',
    'CM3':   'cm3',
    'CM4':   'cm4',
    'CM7':   'cm7',
    'CM23':  'cm0p',   # CM23 ≈ CM0+ for practical peripheral purposes
    'CM33':  'cm33',
    'CM35P': 'cm33',
    'CM55':  'cm55',
    'CM85':  'cm55',
}
# fmt: on

# Fixed ARM-defined base addresses (same on every chip with the same core)
_SCS_BASE = 0xE000_E000
PERIPH_BASES: dict[str, int] = {
    'itm':       0xE000_0000,
    'dwt':       0xE000_1000,
    'systick':   _SCS_BASE + 0x0010,
    'nvic':      _SCS_BASE + 0x0100,
    'scb':       _SCS_BASE + 0x0D00,
    'mpu':       _SCS_BASE + 0x0D90,
    'fpu':       _SCS_BASE + 0x0F30,
    'coredebug': 0xE000_EDF0,
    'sau':       _SCS_BASE + 0x0DD0,
    'dcb':       0xE000_EDF0,   # same as CoreDebug on CM33
}

# CMSIS struct name → our peripheral key
STRUCT_MAP: dict[str, str] = {
    'SysTick_Type':   'systick',
    'SCB_Type':       'scb',
    'MPU_Type':       'mpu',
    'FPU_Type':       'fpu',
    'DWT_Type':       'dwt',
    'ITM_Type':       'itm',
    'CoreDebug_Type': 'coredebug',
    'SAU_Type':       'sau',
    'DCB_Type':       'dcb',
}

# Bit-field macro prefix → peripheral key + register name
# CMSIS macros: SysTick_CTRL_ENABLE_Pos → periph=SysTick, reg=CTRL, field=ENABLE
MACRO_PERIPH_MAP: dict[str, str] = {
    'SysTick': 'systick',
    'SCB':     'scb',
    'MPU':     'mpu',
    'FPU':     'fpu',
    'DWT':     'dwt',
    'ITM':     'itm',
    'CoreDebug': 'coredebug',
    'SAU':     'sau',
    'DCB':     'dcb',
}


# ---------------------------------------------------------------------------
# Data model
# ---------------------------------------------------------------------------

@dataclass
class BitField:
    name: str
    lsb: int
    msb: int
    cpp_type: str = 'bool'


@dataclass
class CoreRegister:
    name: str       # e.g. "CTRL"
    offset: int
    access: str     # rw / ro / wo
    fields: list[BitField] = field(default_factory=list)


@dataclass
class CorePeripheral:
    key: str                              # e.g. "systick"
    base: int
    registers: list[CoreRegister] = field(default_factory=list)


# ---------------------------------------------------------------------------
# Bittype classification (mirrors svd2groov classify_bittype)
# ---------------------------------------------------------------------------

def _classify_1bit(name: str) -> str:
    n = name.upper()
    prefix = 'common::'
    if n.endswith('RST'):                              return f'{prefix}bit_reset'
    if 'LOCK' in n or n.endswith('LCK'):              return f'{prefix}bit_locked'
    if 'RDY' in n:                                    return f'{prefix}bit_ready'
    if 'BSY' in n:                                    return f'{prefix}bit_nready'
    if n.endswith('DIS'):                              return f'{prefix}bit_nenable'
    if n.endswith(('EN', 'IE', 'DE', 'PE', 'FE')):   return f'{prefix}bit_enable'
    if len(n) >= 2 and n[-1] == 'E' and n[-2].isdigit(): return f'{prefix}bit_enable'
    return 'bool'


def _cpp_type(lsb: int, msb: int, name: str) -> str:
    w = msb - lsb + 1
    if w == 1:   return _classify_1bit(name)
    if w <= 8:   return 'std::uint8_t'
    if w <= 16:  return 'std::uint16_t'
    return 'std::uint32_t'


# ---------------------------------------------------------------------------
# CMSIS header parsing
# ---------------------------------------------------------------------------

_QUAL_ACCESS = {'__IOM': 'rw', '__IM': 'ro', '__OM': 'wo'}

# Matches scalar uint32_t members that have an Offset comment
_MEMBER_RE = re.compile(
    r'(__IOM|__IM|__OM)\s+uint32_t\s+(\w+)\s*;'
    r'[^\n]*Offset:\s*0x([0-9A-Fa-f]+)\s*\(([^)]+)\)'
)


def parse_struct(text: str, type_name: str) -> list[tuple[str, int, str]]:
    """Extract (name, offset, access) for scalar uint32_t registers.

    Uses the 'Offset: 0x...' comments CMSIS provides on every member.
    Array and byte-width members are skipped (they don't fit groov's
    static-address model well; handle via CMSIS functions if needed).
    """
    # ponytail: balanced-brace walk avoids regex spanning multiple struct bodies
    pat = re.compile(r'typedef struct\s*\{')
    body = None
    for m in pat.finditer(text):
        depth, pos = 1, m.end()
        while pos < len(text) and depth > 0:
            c = text[pos]
            if c == '{':   depth += 1
            elif c == '}': depth -= 1
            pos += 1
        closing = re.match(r'\s*' + re.escape(type_name) + r'\s*;', text[pos:])
        if closing:
            body = text[m.end():pos - 1]
            break
    if body is None:
        return []

    regs = []
    for m2 in _MEMBER_RE.finditer(body):
        qual, name, offset_hex, _ = m2.groups()
        if 'RESERVED' in name.upper():
            continue
        regs.append((name, int(offset_hex, 16), _QUAL_ACCESS[qual]))
    return regs


def parse_bit_fields(text: str, cmsis_periph: str, reg: str) -> list[BitField]:
    """Extract bit fields from _Pos/_Msk macros for a given peripheral+register."""
    prefix = f'{cmsis_periph}_{reg}_'
    pos_re = re.compile(
        rf'#define\s+{re.escape(prefix)}(\w+)_Pos\s+\(?(\d+)U?\)?')
    # ponytail: drop << requirement — coefficient bit_length() gives width regardless;
    # some CMSIS Msk macros comment out the shift (e.g. (0xFFFFFFUL /*<< Pos*/))
    msk_re = re.compile(
        rf'#define\s+{re.escape(prefix)}(\w+)_Msk\s+'
        rf'\(?(0x[0-9A-Fa-f]+|[0-9]+)UL?')

    pos_map = {m.group(1): int(m.group(2)) for m in pos_re.finditer(text)}
    msk_width: dict[str, int] = {}
    for m in msk_re.finditer(text):
        raw = m.group(2)
        val = int(raw, 16 if raw.startswith('0x') else 10)
        msk_width[m.group(1)] = max(1, val.bit_length())

    fields = []
    for fname, lsb in pos_map.items():
        width = msk_width.get(fname, 1)
        msb = lsb + width - 1
        fields.append(BitField(
            name=fname.lower(),
            lsb=lsb, msb=msb,
            cpp_type=_cpp_type(lsb, msb, fname),
        ))

    return sorted(fields, key=lambda f: -f.lsb)


def parse_cmsis_header(text: str) -> dict[str, CorePeripheral]:
    """Parse a CMSIS core_cm*.h and return all recognised core peripherals."""
    result: dict[str, CorePeripheral] = {}

    for struct_name, pkey in STRUCT_MAP.items():
        raw_regs = parse_struct(text, struct_name)
        if not raw_regs:
            continue

        # Find the CMSIS macro prefix for this peripheral
        cmsis_prefix = next(
            (k for k, v in MACRO_PERIPH_MAP.items() if v == pkey), None)

        registers: list[CoreRegister] = []
        for reg_name, offset, access in raw_regs:
            fields = []
            if cmsis_prefix:
                fields = parse_bit_fields(text, cmsis_prefix, reg_name)
            registers.append(CoreRegister(
                name=reg_name,
                offset=offset,
                access=access,
                fields=fields,
            ))

        result[pkey] = CorePeripheral(
            key=pkey,
            base=PERIPH_BASES[pkey],
            registers=registers,
        )

    return result


# ---------------------------------------------------------------------------
# Code generation
# ---------------------------------------------------------------------------

def _fmt_offset(offset: int) -> str:
    return '0x0' if offset == 0 else f'0x{offset:x}'


def _field_line(f: BitField, reg_access: str, is_last: bool) -> str:
    """Emit a groov::field<> line."""
    # Emit access only when it differs from the register default
    acc_map = {'rw': 'rw', 'ro': 'ro', 'wo': 'wo'}
    comma = '' if is_last else ','
    return (f'               groov::field<"{f.name}", {f.cpp_type}, '
            f'{f.msb}, {f.lsb}>{comma}')


def generate_peripheral_header(periph: CorePeripheral) -> str:
    """Generate a single peripheral header (e.g. common/core/systick.hpp)."""
    lines = [
        '/* File autogenerated with cmsis2groov */',
        '#pragma once',
        '#include <groov/groov.hpp>',
        '#include "../../access.hpp"',
        '#include "../../bittypes.hpp"',
        '',
        'namespace erworks::stm32::core {',
        f'namespace {periph.key} {{',
    ]

    reg_aliases: list[tuple[str, str, int]] = []  # (alias, reg_name_lower, offset)
    for reg in periph.registers:
        rname = reg.name.lower()
        alias = f'{rname}_tt'
        acc = reg.access
        lines += [
            '',
            f'template <stdx::ct_string name,',
            f'          std::uint32_t   baseaddress,',
            f'          std::uint32_t   offset>',
            f'using {alias} =',
            f'  groov::reg<name,',
            f'             std::uint32_t,',
            f'             baseaddress + offset,',
            f'             common::access::{acc},',
        ]
        if reg.fields:
            for i, f in enumerate(reg.fields):
                line = _field_line(f, acc, i == len(reg.fields) - 1)
                if i == len(reg.fields) - 1:
                    line += '>;'
                lines.append(line)
        else:
            # No known bit fields — expose the whole register as a single field
            lines[-1] = lines[-1].rstrip(',')
            lines.append(f'             groov::field<"{rname}", std::uint32_t, 31, 0>>;')
        reg_aliases.append((alias, rname, reg.offset))

    # Group template
    pkey = periph.key
    lines += [
        '',
        f'template <std::uint32_t baseaddress>',
        f'using {pkey}_t =',
        f'  groov::group<"{pkey}",',
        f'               groov::mmio_bus<>,',
    ]
    for i, (alias, rname, offset) in enumerate(reg_aliases):
        comma = '>;' if i == len(reg_aliases) - 1 else ','
        lines.append(
            f'               {alias}<"{rname}", baseaddress, '
            f'{_fmt_offset(offset)}>{comma}')

    lines += [
        '',
        f'inline constexpr std::uint32_t {pkey.upper()}_BASE = '
        f'0x{periph.base:08X}U;',
        '',
        f'}} // namespace {pkey}',
        '} // namespace erworks::stm32::core',
        '',
    ]
    return '\n'.join(lines)


def generate_core_aggregate(variant: str, available: list[str]) -> str:
    """Generate common/core/<variant>.hpp — includes all available peripherals."""
    lines = [
        f'/* File autogenerated with cmsis2groov for {variant} */',
        '#pragma once',
        '',
    ]
    for pkey in available:
        lines.append(f'#include "{variant}/{pkey}.hpp"')
    lines += [
        '',
        f'// Cortex-{variant.upper()} core peripheral instances',
        'namespace erworks::stm32::core {',
    ]
    for pkey in available:
        lines.append(
            f'inline constexpr auto {pkey} = '
            f'{pkey}::{pkey}_t<{pkey}::{pkey.upper()}_BASE>{{}};')
    lines += [
        '} // namespace erworks::stm32::core',
        '',
    ]
    return '\n'.join(lines)


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main() -> None:
    parser = argparse.ArgumentParser(
        description='Generate GROOV core peripheral headers from CMSIS headers')
    parser.add_argument('-o', '--output', required=True,
                        help='Output base directory (e.g. include/stm32/)')
    for v in ('cm0', 'cm0p', 'cm3', 'cm4', 'cm7', 'cm33', 'cm55'):
        parser.add_argument(f'--{v}', metavar='HEADER',
                            help=f'Path to CMSIS core_{v.replace("p","0plus")}.h')
    parser.add_argument('--verbose', action='store_true')
    args = parser.parse_args()

    output_base = Path(args.output)
    core_dir = output_base / 'common' / 'core'

    # Parse each provided CMSIS header, write per-peripheral and aggregate files
    for variant, periph_keys in CORE_PERIPHERALS.items():
        hdr_path = getattr(args, variant, None)
        if not hdr_path:
            continue

        text = Path(hdr_path).read_text()
        peripherals = parse_cmsis_header(text)

        if args.verbose:
            found = sorted(peripherals)
            print(f'{variant}: found {found}')

        variant_dir = core_dir / variant
        variant_dir.mkdir(parents=True, exist_ok=True)

        available: list[str] = []
        for pkey in periph_keys:
            if pkey not in peripherals:
                if args.verbose:
                    print(f'  {variant}: {pkey} not found in header, skipping')
                continue
            content = generate_peripheral_header(peripherals[pkey])
            (variant_dir / f'{pkey}.hpp').write_text(content)
            available.append(pkey)

        aggregate = generate_core_aggregate(variant, available)
        (core_dir / f'{variant}.hpp').write_text(aggregate)
        if args.verbose:
            print(f'  wrote {len(available)} peripheral files + {variant}.hpp')


if __name__ == '__main__':
    main()
