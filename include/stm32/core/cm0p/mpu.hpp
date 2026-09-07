#pragma once

#include <groov/groov.hpp>

#include "../../common/access.hpp"

namespace erworks::stm32::core::mpu {

// NOLINTBEGIN(*-magic-numbers)

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using type_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"reserved0", std::uint8_t, 31, 24>,
                           groov::field<"iregion", std::uint8_t, 23, 16>,
                           groov::field<"dregion", std::uint8_t, 15, 8>,
                           groov::field<"reserved1", std::uint8_t, 7, 1>,
                           groov::field<"separate", bool, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using ctrl_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"reserved0", std::uint32_t, 31, 3, common::access::ro>,
  groov::field<"privdefena", bool, 2, 2>,
  groov::field<"hfnmiena", bool, 1, 1>,
  groov::field<"enable", bool, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using rnr_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"reserved0", std::uint32_t, 31, 8, common::access::ro>,
  groov::field<"region", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using rbar_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::rw,
                           groov::field<"addr", std::uint32_t, 31, 8>,
                           groov::field<"valid", bool, 4, 4>,
                           groov::field<"region", std::uint8_t, 3, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using rasr_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"reserved0", std::uint8_t, 31, 29, common::access::ro>,
  groov::field<"xn", bool, 28, 28>,
  groov::field<"reserved1", bool, 27, 27, common::access::ro>,
  groov::field<"ap", std::uint8_t, 26, 24>,
  groov::field<"reserved2", std::uint8_t, 23, 19, common::access::ro>,
  groov::field<"s", bool, 18, 18>,
  groov::field<"c", bool, 17, 17>,
  groov::field<"b", bool, 16, 16>,
  groov::field<"srd", std::uint8_t, 15, 8>,
  groov::field<"reserved3", std::uint8_t, 7, 6, common::access::ro>,
  groov::field<"size", std::uint8_t, 5, 1>,
  groov::field<"enable", bool, 0, 0>>;

template <std::uint32_t Baseaddress>
using mpu_t = groov::group<"mpu",
                           groov::mmio_bus<>,
                           type_tt<"type", Baseaddress, 0x0>,
                           ctrl_tt<"ctrl", Baseaddress, 0x4>,
                           rnr_tt<"rnr", Baseaddress, 0x8>,
                           rbar_tt<"rbar", Baseaddress, 0xc>,
                           rasr_tt<"rasr", Baseaddress, 0x10>>;

inline constexpr std::uint32_t MPU_BASE = 0xE000'ED90U;

// NOLINTEND(*-magic-numbers)
} // namespace erworks::stm32::core::mpu
