#pragma once

#include <groov/groov.hpp>

#include "../../common/access.hpp"
#include "../../common/bittypes.hpp"

namespace erworks::stm32::core::scb {

// NOLINTBEGIN(*-magic-numbers)

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using cpuid_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::ro,
                            groov::field<"implementer", std::uint8_t, 31, 24>,
                            groov::field<"variant", std::uint8_t, 23, 20>,
                            groov::field<"architecture", std::uint8_t, 19, 16>,
                            groov::field<"partno", std::uint16_t, 15, 4>,
                            groov::field<"revision", std::uint8_t, 3, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using icsr_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"nmipendset", common::bit_reset, 31, 31>,
  groov::field<"reserved0", std::uint8_t, 30, 29, common::access::ro>,
  groov::field<"pend", bool, 28, 28>,
  groov::field<"pendsvclr", common::bit_reset, 27, 27, common::access::wo>,
  groov::field<"pendstset", common::bit_reset, 26, 26>,
  groov::field<"pendstclr", common::bit_reset, 25, 25, common::access::wo>,
  groov::field<"reserved0", bool, 24, 24>,
  groov::field<"ispreempt", bool, 23, 23>,
  groov::field<"isrpending", bool, 22, 22, common::access::ro>,
  groov::field<"reserved1", bool, 21, 21, common::access::ro>,
  groov::field<"vectpending", std::uint16_t, 20, 12, common::access::ro>,
  groov::field<"reserved2", std::uint8_t, 11, 9, common::access::ro>,
  groov::field<"vectactive", std::uint16_t, 8, 0, common::access::ro>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using aircr_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"vectkey", std::uint16_t, 31, 16>,
  groov::field<"endianess", bool, 15, 15, common::access::ro>,
  groov::field<"reserved0", std::uint16_t, 14, 3, common::access::ro>,
  groov::field<"sysresetreq", bool, 2, 2, common::access::wo>,
  groov::field<"vectclractive", bool, 1, 1, common::access::wo>,
  groov::field<"reserved1", bool, 0, 0, common::access::ro>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using scr_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"reserved0", std::uint32_t, 31, 5, common::access::ro>,
  groov::field<"sevonpend", bool, 4, 4>,
  groov::field<"reserved1", bool, 3, 3, common::access::ro>,
  groov::field<"sleepdeep", bool, 2, 2>,
  groov::field<"sleeponexit", bool, 1, 1>,
  groov::field<"reserved2", bool, 0, 0, common::access::ro>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using ccr_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"reserved0", std::uint32_t, 31, 10, common::access::ro>,
  groov::field<"stkalign", bool, 9, 9>,
  groov::field<"reserved1", std::uint8_t, 8, 4, common::access::ro>,
  groov::field<"unalign_trp", common::bit_enable, 3, 3>,
  groov::field<"reserved2", std::uint8_t, 2, 0, common::access::ro>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using shcsr_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"reserved0", std::uint16_t, 31, 16, common::access::ro>,
  groov::field<"svcallpended", bool, 15, 15>,
  groov::field<"reserved1", std::uint16_t, 14, 0, common::access::ro>>;

template<stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using shprii_tt = groov::reg<
Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"pri11", std::uint8_t, 31, 24>,
  groov::field<"reserved0", std::uint32_t, 23, 0, common::access::ro>>;

template<stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
  using shpriii_tt = groov::reg<
  Name, std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"pri15", std::uint8_t, 31, 24>,
  groov::field<"pri14", std::uint8_t, 23, 16>,
  groov::field<"reserved0", std::uint16_t, 15,0, common::access::ro>>;

// scb peripheral

template<std::uint32_t Baseaddress>
using scb_t =
groov::group<"scb",
  groov::mmio_bus<>,
  cpuid_tt<"cpuid", Baseaddress, 0x0>,
  icsr_tt<"icsr", Baseaddress, 0x4>,
  aircr_tt<"aircr", Baseaddress, 0xc>,
  scr_tt<"scr", Baseaddress, 0x10>,
  ccr_tt<"ccr", Baseaddress, 0x14>,
  shprii_tt<"shpr2", Baseaddress, 0x1C>,
  shpriii_tt<"shpr3", Baseaddress, 0x20>,
  shcsr_tt<"shcsr", Baseaddress, 0x24>>;

inline constexpr std::uint32_t SCB_BASE     = 0xE000'ED00U;

// NOLINTEND(*-magic-numbers)
} // namespace erworks::stm32::core::scb
