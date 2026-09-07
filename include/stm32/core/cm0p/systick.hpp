#pragma once

#include <groov/groov.hpp>

#include "../../common/access.hpp"
#include "../../common/bittypes.hpp"

// NOLINTBEGIN(*-magic-numbers)
namespace erworks::stm32::core::systick {

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using ctrl_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"reserved1", std::uint16_t, 31, 17, common::access::ro>,
  groov::field<"countflag", bool, 16, 16>,
  groov::field<"reserved0", std::uint16_t, 15, 3, common::access::ro>,
  groov::field<"clksource", bool, 2, 2>,
  groov::field<"tickint", bool, 1, 1>,
  groov::field<"enable", bool, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using load_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"reserved0", std::uint32_t, 31, 24, common::access::ro>,
  groov::field<"reload", std::uint32_t, 23, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using val_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"reserved0", std::uint16_t, 31, 24, common::access::ro>,
  groov::field<"current", std::uint32_t, 23, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using calib_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::ro,
  groov::field<"noref", bool, 31, 31>,
  groov::field<"skew", bool, 30, 30>,
  groov::field<"reserved0", std::uint16_t, 29, 24, common::access::ro>,
  groov::field<"tenms", std::uint32_t, 23, 0>>;

// systic peripheral

template <std::uint32_t Baseaddress>
using systick_t = groov::group<"systick",
                               groov::mmio_bus<>,
                               ctrl_tt<"ctrl", Baseaddress, 0x0>,
                               load_tt<"load", Baseaddress, 0x4>,
                               val_tt<"val", Baseaddress, 0x8>,
                               calib_tt<"calib", Baseaddress, 0xc>>;

inline constexpr std::uint32_t SYSTICK_BASE = 0xE000E010U;

// NOLINTEND(*-magic-numbers)
} // namespace erworks::stm32::core::systick
