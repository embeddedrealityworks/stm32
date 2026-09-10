#pragma once

#include <groov/groov.hpp>

#include "../../common/access.hpp"
#include "../../common/bittypes.hpp"

// NOLINTBEGIN(*-magic-numbers)

namespace erworks::stm32::core::sau {

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using ctrl_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::rw,
                           groov::field<"reserved0", std::uint32_t, 31, 2, common::access::ro>,
                           groov::field<"allns", bool, 1, 1>,
                           groov::field<"enable", bool, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using type_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"reserved0", std::uint32_t, 31, 8, common::access::ro>,
                           groov::field<"sregion", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using rnr_tt = groov::reg<Name,
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
                           groov::field<"baddr", std::uint32_t, 31, 5>,
                           groov::field<"reserved0", std::uint8_t, 4, 0, common::access::ro>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using rlar_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::rw,
                           groov::field<"laddr", std::uint32_t, 31, 5>,
                           groov::field<"reserved0", std::uint8_t, 4, 2, common::access::ro>,
                           groov::field<"nsc", bool, 1, 1>,
                           groov::field<"enable", bool, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using sfsr_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::rw,
                           groov::field<"reserved0", std::uint32_t, 31, 8, common::access::ro>,
                           groov::field<"lserr", bool, 7, 7>,
                           groov::field<"sfarvalid", bool, 6, 6>,
                           groov::field<"lsperr", bool, 5, 5>,
                           groov::field<"invtran", bool, 4, 4>,
                           groov::field<"auviol", bool, 3, 3>,
                           groov::field<"inver", bool, 2, 2>,
                           groov::field<"invis", bool, 1, 1>,
                           groov::field<"invep", bool, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using sfar_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::rw,
                           groov::field<"sfar", std::uint32_t, 31, 0>>;

template <std::uint32_t Baseaddress>
using sau_t = groov::group<"sau",
                           groov::mmio_bus<>,
                           ctrl_tt<"ctrl", Baseaddress, 0x0>,
                           type_tt<"type", Baseaddress, 0x4>,
                           rnr_tt<"rnr", Baseaddress, 0x8>,
                           rbar_tt<"rbar", Baseaddress, 0xc>,
                           rlar_tt<"rlar", Baseaddress, 0x10>,
                           sfsr_tt<"sfsr", Baseaddress, 0x14>,
                           sfar_tt<"sfar", Baseaddress, 0x18>>;

inline constexpr std::uint32_t SAU_BASE = 0xE000'EDD0U;

} // namespace erworks::stm32::core::sau

// NOLINTEND(*-magic-numbers)
