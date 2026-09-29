#!/usr/bin/env python3
"""Parse STM32CubeMX .ioc file → Meson [properties] machine file.

Usage: ioc-parse.py <input.ioc> [output.ini]
  output.ini  optional output path; writes to stdout if omitted
"""

import re
import sys
from pathlib import Path


FAMILY_CORES = {
    "F0": "cortex-m0",    "F1": "cortex-m3",    "F2": "cortex-m3",
    "F3": "cortex-m4",    "F4": "cortex-m4",    "F7": "cortex-m7",
    "G0": "cortex-m0plus","G4": "cortex-m4",    "H7": "cortex-m7",
    "L0": "cortex-m0plus","L1": "cortex-m3",    "L4": "cortex-m4",
    "L5": "cortex-m33",   "U5": "cortex-m33",   "WB": "cortex-m4",
    "WL": "cortex-m4",
}

FAMILY_FPU = {
    "F0": "none",         "F1": "none",         "F2": "none",
    "F3": "fpv4-sp-d16",  "F4": "fpv4-sp-d16",  "F7": "fpv5-sp-d16",
    "G0": "none",         "G4": "fpv4-sp-d16",  "H7": "fpv5-d16",
    "L0": "none",         "L1": "none",         "L4": "fpv4-sp-d16",
    "L5": "fpv5-sp-d16",  "U5": "fpv5-sp-d16",  "WB": "fpv4-sp-d16",
    "WL": "none",
}

# Flash size code (4th char of part number) → KB
FLASH_SIZES = {
    "4": 16,  "6": 32,  "8": 64,  "B": 128, "C": 256,
    "D": 384, "E": 512, "F": 768, "G": 1024,"H": 1536,"I": 2048,
}

# Default RAM by family (KB)
FAMILY_RAM = {
    "F0": 8,   "F1": 20,  "F2": 128, "F3": 40,  "F4": 128,
    "F7": 256, "G0": 8,   "G4": 32,  "H7": 512, "L0": 8,
    "L1": 32,  "L4": 96,  "L5": 256, "U5": 256, "WB": 64, "WL": 64,
}

# IOC RCC key → output property name
# CubeMX quirks: oscillator inputs use _VALUE (all-caps), derived freqs
# use _Value (mixed case), PLL source is PLLSourceVirtual not PLLSource.
CLOCK_KEYS = {
    # Oscillator inputs
    "RCC.HSE_VALUE":          "hse_hz",
    "RCC.HSI_VALUE":          "hsi_hz",
    "RCC.LSE_VALUE":          "lse_hz",
    "RCC.LSI_VALUE":          "lsi_hz",
    "RCC.MSI_VALUE":          "msi_hz",
    # Clock mux selections
    "RCC.PLLSourceVirtual":   "pll_source",
    "RCC.SYSCLKSource":       "sysclk_source",
    "RCC.I2SSource":          "i2s_source",
    "RCC.RTCClockSelection":  "rtc_source",
    "RCC.MCO1Source":         "mco1_source",
    "RCC.MCO2Source":         "mco2_source",
    # F1 PLL
    "RCC.PLLMUL":             "pll_mul",
    "RCC.HSEDivPLL":          "hse_prediv",
    # F2/F4/F7/H7/G4/L4/U5 PLL
    "RCC.PLLM":               "pll_m",
    "RCC.PLLN":               "pll_n",
    "RCC.PLLP":               "pll_p",
    "RCC.PLLQ":               "pll_q",
    "RCC.PLLR":               "pll_r",
    # Bus prescalers
    "RCC.AHBCLKDivider":      "ahb_div",
    "RCC.APB1CLKDivider":     "apb1_div",
    "RCC.APB2CLKDivider":     "apb2_div",
    "RCC.APB3CLKDivider":     "apb3_div",
    # Peripheral prescalers
    "RCC.ADCPresc":           "adc_presc",
    "RCC.USBPrescaler":       "usb_presc",
    "RCC.MCO1Div":            "mco1_div",
    "RCC.MCO2Div":            "mco2_div",
    # Derived frequencies
    "RCC.SYSCLKFreq_VALUE":   "sysclk_hz",
    "RCC.HCLKFreq_Value":     "hclk_hz",
    "RCC.AHBFreq_Value":      "ahb_hz",
    "RCC.APB1Freq_Value":     "pclk1_hz",
    "RCC.APB2Freq_Value":     "pclk2_hz",
    "RCC.APB1TimFreq_Value":  "apb1_timer_hz",
    "RCC.APB2TimFreq_Value":  "apb2_timer_hz",
    "RCC.FCLKCortexFreq_Value":"fclk_hz",
    "RCC.CortexFreq_Value":   "cortex_hz",
    "RCC.PLLCLKFreq_Value":   "pll_hz",
    "RCC.VCOOutputFreq_Value":"vco_hz",
    "RCC.VCOInputFreq_Value": "vco_in_hz",
    "RCC.USBFreq_Value":      "usb_hz",
    "RCC.SDIOFreq_Value":     "sdio_hz",
    "RCC.RTCFreq_Value":      "rtc_hz",
    "RCC.ADCFreqValue":       "adc_hz",
    "RCC.48MHZClocksFreq_Value": "clk48_hz",
    "RCC.MCO2PinFreq_Value":  "mco2_hz",
}

_RCC_SKIP = {"FamilyName", "IPParameters"}
_FREQ_RE  = re.compile(r"(?:Freq_Value|_VALUE|FreqValue|ClocksFreq_Value)$")


def _rcc_fallback_name(param: str) -> str:
    """CamelCase RCC param → snake_case identifier."""
    name = _FREQ_RE.sub("_hz", param)
    name = re.sub(r"([A-Z]+)([A-Z][a-z])", r"\1_\2", name)
    name = re.sub(r"([a-z\d])([A-Z])", r"\1_\2", name)
    name = name.lower()
    name = re.sub(r"[^a-z0-9_]", "_", name)
    name = re.sub(r"_+", "_", name).strip("_")
    return ("rcc_" + name) if name and name[0].isdigit() else name


def parse_ioc(path: Path) -> dict[str, str]:
    data = {}
    for line in path.read_text().splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        if "=" in line:
            k, _, v = line.partition("=")
            data[k.strip()] = v.strip()
    return data


def extract_mcu_info(raw: dict[str, str]) -> dict[str, str]:
    name = raw.get("Mcu.UserName", raw.get("Mcu.Name", ""))
    info: dict[str, str] = {"mcu_name": name}

    m = re.match(r"STM32([A-Z]\d)(\d{2})([A-Z])([A-Z0-9])([A-Z])", name)
    if m:
        family     = m.group(1)
        flash_code = m.group(4)
        info["mcu_family"]  = family.lower()
        info["mcu_line"]    = f"{family.lower()}{m.group(2)}"
        info["mcu_core"]    = FAMILY_CORES.get(family, "cortex-m3")
        info["mcu_fpu"]     = FAMILY_FPU.get(family, "none")
        info["flash_kb"]    = str(FLASH_SIZES.get(flash_code, 64))
        info["ram_kb"]      = str(FAMILY_RAM.get(family, 20))

    if "Mcu.Package" in raw:
        info["mcu_package"] = raw["Mcu.Package"]

    # Full stm32 name used by register-definition subproject headers,
    # e.g. 'stm32f103' → include/stm32/stm32f103/stm32f103.hpp
    if "mcu_line" in info:
        info["stm32_mcu"] = "stm32" + info["mcu_line"]

    return info


def extract_memory(info: dict[str, str], raw: dict[str, str]) -> dict[str, str]:
    family   = info.get("mcu_family", "f1").upper()
    flash_kb = int(info.get("flash_kb", 64))
    ram_kb   = int(info.get("ram_kb", 20))

    ram_origin = "0x24000000" if family == "H7" else "0x20000000"

    return {
        "flash_origin": "0x08000000",
        "flash_kb":     str(flash_kb),
        "ram_origin":   ram_origin,
        "ram_kb":       str(ram_kb),
        "heap_size":    raw.get("ProjectManager.HeapSize",  "0x200"),
        "stack_size":   raw.get("ProjectManager.StackSize", "0x400"),
    }


def extract_clocks(raw: dict[str, str]) -> dict[str, str]:
    clocks: dict[str, str] = {}

    for ioc_key, out_key in CLOCK_KEYS.items():
        if ioc_key in raw:
            clocks[out_key] = raw[ioc_key]

    already = {k[4:] for k in CLOCK_KEYS if k.startswith("RCC.")}
    for param in raw.get("RCC.IPParameters", "").split(","):
        param = param.strip()
        if not param or param in _RCC_SKIP or param in already:
            continue
        rcc_key = f"RCC.{param}"
        if rcc_key in raw:
            name = _rcc_fallback_name(param)
            if name and name not in clocks:
                clocks[name] = raw[rcc_key]

    return clocks


def extract_peripherals(raw: dict[str, str]) -> list[str]:
    result = []
    for i in range(int(raw.get("Mcu.IPNb", 0))):
        ip = raw.get(f"Mcu.IP{i}", "")
        if ip and ip not in ("NVIC", "SYS", "RCC"):
            result.append(ip.lower())
    return sorted(set(result))


def _prop(key: str, value: str) -> str:
    """Format one [properties] line; integers unquoted, strings quoted."""
    try:
        int(value)
        return f"{key} = {value}"
    except ValueError:
        return f"{key} = '{value}'"


def format_machine(raw: dict[str, str]) -> str:
    mcu_info    = extract_mcu_info(raw)
    memory      = extract_memory(mcu_info, raw)
    clocks      = extract_clocks(raw)
    peripherals = extract_peripherals(raw)

    lines = ["[properties]"]

    lines.append("")
    lines.append("# MCU identity")
    for k in ["mcu_name", "mcu_family", "mcu_line", "stm32_mcu",
              "mcu_core", "mcu_fpu", "mcu_package"]:
        if k in mcu_info:
            lines.append(_prop(k, mcu_info[k]))

    lines.append("")
    lines.append("# Memory layout")
    for k in ["flash_origin", "flash_kb", "ram_origin", "ram_kb",
              "heap_size", "stack_size"]:
        if k in memory:
            lines.append(_prop(k, memory[k]))

    if clocks:
        lines.append("")
        lines.append("# Clock tree")
        for k, v in sorted(clocks.items()):
            lines.append(_prop(k, v))

    if peripherals:
        lines.append("")
        lines.append("# Enabled peripherals")
        lines.append(f"peripherals = '{','.join(peripherals)}'")

    lines.append("")
    return "\n".join(lines)


def main() -> None:
    if len(sys.argv) not in (2, 3):
        print(f"Usage: {sys.argv[0]} <input.ioc> [output.ini]",
              file=sys.stderr)
        sys.exit(1)

    ioc_path = Path(sys.argv[1])
    if not ioc_path.exists():
        print(f"Error: {ioc_path} not found", file=sys.stderr)
        sys.exit(1)

    output = format_machine(parse_ioc(ioc_path))

    if len(sys.argv) == 3:
        Path(sys.argv[2]).write_text(output)
    else:
        print(output, end="")


if __name__ == "__main__":
    main()
