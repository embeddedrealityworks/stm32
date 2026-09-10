#pragma once

#include <groov/groov.hpp>

#include "../../common/access.hpp"
#include "../../common/bittypes.hpp"

// NOLINTBEGIN(*-magic-numbers)

namespace erworks::stm32::core::mpu {

template <stdx::ct_string Name,
          std::uint32_t   Baseaddress,
          std::uint32_t   Offset>
using type_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::ro,
               groov::field<"iregion", std::uint8_t, 23, 16>,
               groov::field<"dregion", std::uint8_t, 15, 8>,
               groov::field<"separate", bool, 0, 0>>;

template <stdx::ct_string Name,
          std::uint32_t   Baseaddress,
          std::uint32_t   Offset>
using ctrl_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
               groov::field<"privdefena", bool, 2, 2>,
               groov::field<"hfnmiena", bool, 1, 1>,
               groov::field<"enable", bool, 0, 0>>;

template <stdx::ct_string Name,
          std::uint32_t   Baseaddress,
          std::uint32_t   Offset>
using rnr_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
               groov::field<"region", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name,
          std::uint32_t   Baseaddress,
          std::uint32_t   Offset>
using rbar_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
               groov::field<"base", std::uint32_t, 31, 5>,
               groov::field<"sh", std::uint8_t, 4, 3>,
               groov::field<"ap", std::uint8_t, 2, 1>,
               groov::field<"xn", bool, 0, 0>>;

template <stdx::ct_string Name,
          std::uint32_t   Baseaddress,
          std::uint32_t   Offset>
using rlar_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
               groov::field<"limit", std::uint32_t, 31, 5>,
               groov::field<"pxn", bool, 4, 4>,
               groov::field<"attrindx", std::uint8_t, 3, 1>,
               groov::field<"en", common::bit_enable, 0, 0>>;

template <stdx::ct_string Name,
          std::uint32_t   Baseaddress,
          std::uint32_t   Offset>
using rbar_a1_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"rbar_a1", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name,
          std::uint32_t   Baseaddress,
          std::uint32_t   Offset>
using rlar_a1_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"rlar_a1", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name,
          std::uint32_t   Baseaddress,
          std::uint32_t   Offset>
using rbar_a2_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"rbar_a2", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name,
          std::uint32_t   Baseaddress,
          std::uint32_t   Offset>
using rlar_a2_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"rlar_a2", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name,
          std::uint32_t   Baseaddress,
          std::uint32_t   Offset>
using rbar_a3_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"rbar_a3", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name,
          std::uint32_t   Baseaddress,
          std::uint32_t   Offset>
using rlar_a3_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"rlar_a3", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name,
          std::uint32_t   Baseaddress,
          std::uint32_t   Offset>
using mair0_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
               groov::field<"attr3", std::uint8_t, 31, 24>,
               groov::field<"attr2", std::uint8_t, 23, 16>,
               groov::field<"attr1", std::uint8_t, 15, 8>,
               groov::field<"attr0", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name,
          std::uint32_t   Baseaddress,
          std::uint32_t   Offset>
using mair1_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
               groov::field<"attr7", std::uint8_t, 31, 24>,
               groov::field<"attr6", std::uint8_t, 23, 16>,
               groov::field<"attr5", std::uint8_t, 15, 8>,
               groov::field<"attr4", std::uint8_t, 7, 0>>;

template <std::uint32_t Baseaddress>
using mpu_t =
  groov::group<"mpu",
               groov::mmio_bus<>,
               type_tt<"type", Baseaddress, 0x0>,
               ctrl_tt<"ctrl", Baseaddress, 0x4>,
               rnr_tt<"rnr", Baseaddress, 0x8>,
               rbar_tt<"rbar", Baseaddress, 0xc>,
               rlar_tt<"rlar", Baseaddress, 0x10>,
               rbar_a1_tt<"rbar_a1", Baseaddress, 0x14>,
               rlar_a1_tt<"rlar_a1", Baseaddress, 0x18>,
               rbar_a2_tt<"rbar_a2", Baseaddress, 0x1c>,
               rlar_a2_tt<"rlar_a2", Baseaddress, 0x20>,
               rbar_a3_tt<"rbar_a3", Baseaddress, 0x24>,
               rlar_a3_tt<"rlar_a3", Baseaddress, 0x28>,
               mair0_tt<"mair0", Baseaddress, 0x30>,
               mair1_tt<"mair1", Baseaddress, 0x34>>;

inline constexpr std::uint32_t MPU_BASE = 0xE000ED90U;

} // namespace erworks::stm32::core::mpu

  // NOLINTEND(*-magic-numbers)
