#pragma once

#include <groov/groov.hpp>

#include "../../common/access.hpp"
#include "../../common/bittypes.hpp"

// NOLINTBEGIN(*-magic-numbers)

namespace erworks::stm32::core::itm {

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using u32_tt = groov::reg<Name,
                          std::uint32_t,
                          Baseaddress + Offset,
                          common::access::wo,
                          groov::field<"u32", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using ter_tt = groov::reg<Name,
                          std::uint32_t,
                          Baseaddress + Offset,
                          common::access::rw,
                          groov::field<"ter", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using tpr_tt = groov::reg<Name,
                          std::uint32_t,
                          Baseaddress + Offset,
                          common::access::rw,
                          groov::field<"privmask", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using tcr_tt = groov::reg<Name,
                          std::uint32_t,
                          Baseaddress + Offset,
                          common::access::rw,
                          groov::field<"busy", bool, 23, 23>,
                          groov::field<"tracebusid", std::uint8_t, 22, 16>,
                          groov::field<"gtsfreq", std::uint8_t, 11, 10>,
                          groov::field<"tsprescale", std::uint8_t, 9, 8>,
                          groov::field<"stallena", bool, 5, 5>,
                          groov::field<"swoena", bool, 4, 4>,
                          groov::field<"dwtena", bool, 3, 3>,
                          groov::field<"syncena", bool, 2, 2>,
                          groov::field<"tsena", bool, 1, 1>,
                          groov::field<"itmena", bool, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using lar_tt = groov::reg<Name,
                          std::uint32_t,
                          Baseaddress + Offset,
                          common::access::wo,
                          groov::field<"lar", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using lsr_tt = groov::reg<Name,
                          std::uint32_t,
                          Baseaddress + Offset,
                          common::access::ro,
                          groov::field<"byteacc", bool, 2, 2>,
                          groov::field<"access", bool, 1, 1>,
                          groov::field<"present", bool, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using devarch_tt = groov::reg<Name,
                              std::uint32_t,
                              Baseaddress + Offset,
                              common::access::ro,
                              groov::field<"devarch", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using pid4_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"pid4", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using pid5_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"pid5", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using pid6_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"pid6", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using pid7_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"pid7", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using pid0_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"pid0", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using pid1_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"pid1", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using pid2_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"pid2", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using pid3_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"pid3", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using cid0_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"cid0", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using cid1_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"cid1", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using cid2_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"cid2", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using cid3_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"cid3", std::uint32_t, 31, 0>>;

template <std::uint32_t Baseaddress>
using itm_t = groov::group<"itm",
                           groov::mmio_bus<>,
                           u32_tt<"u32", Baseaddress, 0x0>,
                           ter_tt<"ter", Baseaddress, 0xe00>,
                           tpr_tt<"tpr", Baseaddress, 0xe40>,
                           tcr_tt<"tcr", Baseaddress, 0xe80>,
                           lar_tt<"lar", Baseaddress, 0xfb0>,
                           lsr_tt<"lsr", Baseaddress, 0xfb4>,
                           devarch_tt<"devarch", Baseaddress, 0xfbc>,
                           pid4_tt<"pid4", Baseaddress, 0xfd0>,
                           pid5_tt<"pid5", Baseaddress, 0xfd4>,
                           pid6_tt<"pid6", Baseaddress, 0xfd8>,
                           pid7_tt<"pid7", Baseaddress, 0xfdc>,
                           pid0_tt<"pid0", Baseaddress, 0xfe0>,
                           pid1_tt<"pid1", Baseaddress, 0xfe4>,
                           pid2_tt<"pid2", Baseaddress, 0xfe8>,
                           pid3_tt<"pid3", Baseaddress, 0xfec>,
                           cid0_tt<"cid0", Baseaddress, 0xff0>,
                           cid1_tt<"cid1", Baseaddress, 0xff4>,
                           cid2_tt<"cid2", Baseaddress, 0xff8>,
                           cid3_tt<"cid3", Baseaddress, 0xffc>>;

inline constexpr std::uint32_t ITM_BASE = 0xE000'0000U;

} // namespace erworks::stm32::core::itm

// NOLINTEND(*-magic-numbers)
