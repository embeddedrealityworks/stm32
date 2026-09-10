#pragma once

#include <groov/groov.hpp>

#include "../../common/access.hpp"
#include "../../common/bittypes.hpp"

// NOLINTBEGIN(*-magic-numbers)
namespace erworks::stm32::core::coredebug {

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using dhcsr_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"s_reset_st", bool, 25, 25>,
             groov::field<"s_retire_st", bool, 24, 24>,
             groov::field<"s_lockup", common::bit_locked, 19, 19>,
             groov::field<"s_sleep", bool, 18, 18>,
             groov::field<"s_halt", bool, 17, 17>,
             groov::field<"dbgkey", std::uint16_t, 31, 16>,
             groov::field<"s_regrdy", common::bit_ready, 16, 16>,
             groov::field<"c_snapstall", bool, 5, 5>,
             groov::field<"c_maskints", bool, 3, 3>,
             groov::field<"c_step", bool, 2, 2>,
             groov::field<"c_halt", bool, 1, 1>,
             groov::field<"c_debugen", common::bit_enable, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using dcrsr_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::wo,
                            groov::field<"regwnr", bool, 16, 16>,
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
                            groov::field<"trcena", bool, 24, 24>,
                            groov::field<"mon_req", bool, 19, 19>,
                            groov::field<"mon_step", bool, 18, 18>,
                            groov::field<"mon_pend", bool, 17, 17>,
                            groov::field<"mon_en", common::bit_enable, 16, 16>,
                            groov::field<"vc_harderr", bool, 10, 10>,
                            groov::field<"vc_interr", bool, 9, 9>,
                            groov::field<"vc_buserr", bool, 8, 8>,
                            groov::field<"vc_staterr", bool, 7, 7>,
                            groov::field<"vc_chkerr", bool, 6, 6>,
                            groov::field<"vc_nocperr", bool, 5, 5>,
                            groov::field<"vc_mmerr", bool, 4, 4>,
                            groov::field<"vc_corereset", bool, 0, 0>>;

template <std::uint32_t Baseaddress>
using coredebug_t = groov::group<"coredebug",
                                 groov::mmio_bus<>,
                                 dhcsr_tt<"dhcsr", Baseaddress, 0x0>,
                                 dcrsr_tt<"dcrsr", Baseaddress, 0x4>,
                                 dcrdr_tt<"dcrdr", Baseaddress, 0x8>,
                                 demcr_tt<"demcr", Baseaddress, 0xc>>;

inline constexpr std::uint32_t COREDEBUG_BASE = 0xE000'EDF0U;

} // namespace erworks::stm32::core::coredebug

// NOLINTEND(*-magic-numbers)
