#pragma once

#include <groov/groov.hpp>

#include "../../common/access.hpp"
#include "../../common/bittypes.hpp"

namespace erworks::stm32::core::coredebug {

// NOLINTBEGIN(*-magic-numbers)
template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using dhcsr_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::rw,
  groov::field<"reserved0", std::uint8_t, 31, 26, common::access::ro>,
  groov::field<"s_reset_st", bool, 25, 25>,
  groov::field<"s_retire_st", bool, 24, 24>,
  groov::field<"reserved1", std::uint8_t, 23, 20, common::access::ro>,
  groov::field<"s_lockup", common::bit_locked, 19, 19>,
  groov::field<"s_sleep", bool, 18, 18>,
  groov::field<"s_halt", bool, 17, 17>,
  groov::field<"s_regrdy", common::bit_ready, 16, 16>,
  groov::field<"reserved2", std::uint16_t, 15, 6, common::access::ro>,
  groov::field<"c_snapstall", bool, 5, 5>,
  groov::field<"reserved3", bool, 4, 4, common::access::ro>,
  groov::field<"c_maskints", bool, 3, 3>,
  groov::field<"c_step", bool, 2, 2>,
  groov::field<"c_halt", bool, 1, 1>,
  groov::field<"c_debugen", common::bit_enable, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using dcrsr_tt = groov::reg<
  Name,
  std::uint32_t,
  Baseaddress + Offset,
  common::access::wo,
  groov::field<"reserved0", std::uint16_t, 31, 17, common::access::ro>,
  groov::field<"regwnr", bool, 16, 16>,
  groov::field<"reserved1", std::uint16_t, 15, 5, common::access::ro>,
  groov::field<"regsel", std::uint8_t, 4, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using dcrdr_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"dcrdr", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using demcr_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"reserved3", std::uint8_t, 31, 25, common::access::ro>,
                            groov::field<"trcena", common::bit_enable, 24, 24>,
                            groov::field<"reserved2", std::uint8_t, 23, 20, common::access::ro>,
                            groov::field<"mon_req", bool, 19, 19>,
                            groov::field<"mon_step", bool, 18, 18>,
                            groov::field<"mon_pend", bool, 17, 17>,
                            groov::field<"mon_en", common::bit_enable, 16, 16>,
                            groov::field<"reserved1", std::uint8_t, 15, 11, common::access::ro>,
                            groov::field<"vc_harderr", common::bit_enable, 10, 10>,
                            groov::field<"vc_interr", common::bit_enable, 9, 9>,
                            groov::field<"vc_buserr", common::bit_enable, 8, 8>,
                            groov::field<"vc_staterr", common::bit_enable, 7, 7>,
                            groov::field<"vc_chkerr", common::bit_enable, 6, 6>,
                            groov::field<"vc_nocperr", common::bit_enable, 5, 5>,
                            groov::field<"vc_mmerr", common::bit_enable, 4, 4>,
                            groov::field<"reserved0", std::uint8_t, 3, 1, common::access::ro>,
                            groov::field<"vc_corereset", common::bit_enable, 0, 0>>;

template <std::uint32_t Baseaddress>
using coredebug_t = groov::group<"coredebug",
                                 groov::mmio_bus<>,
                                 dhcsr_tt<"dhcsr", Baseaddress, 0x0>,
                                 dcrsr_tt<"dcrsr", Baseaddress, 0x4>,
                                 dcrdr_tt<"dcrdr", Baseaddress, 0x8>,
                                 demcr_tt<"demcr", Baseaddress, 0xc>>;

inline constexpr std::uint32_t COREDEBUG_BASE = 0xE000'EDF0U;

// NOLINTEND(*-magic-numbers)

} // namespace erworks::stm32::core::coredebug
