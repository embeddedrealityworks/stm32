#pragma once

#include <groov/groov.hpp>

#include "../../common/access.hpp"
#include "../../common/bittypes.hpp"

// NOLINTBEGIN(*-magic-numbers)
namespace erworks::stm32::core::dwt {

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using ctrl_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::rw,
                           groov::field<"numcomp", std::uint8_t, 31, 28>,
                           groov::field<"notrcpkt", bool, 27, 27>,
                           groov::field<"noexttrig", bool, 26, 26>,
                           groov::field<"nocyccnt", bool, 25, 25>,
                           groov::field<"noprfcnt", bool, 24, 24>,
                           groov::field<"reserved1", bool, 23, 23, common::access::ro>,
                           groov::field<"cycevtena", common::bit_enable, 22, 22>,
                           groov::field<"foldevtena", common::bit_enable, 21, 21>,
                           groov::field<"lsuevtena", common::bit_enable, 20, 20>,
                           groov::field<"sleepevtena", common::bit_enable, 19, 19>,
                           groov::field<"excevtena", common::bit_enable, 18, 18>,
                           groov::field<"cpievtena", common::bit_enable, 17, 17>,
                           groov::field<"exctrcena", common::bit_enable, 16, 16>,
                           groov::field<"reserved0", std::uint8_t, 15, 13, common::access::ro>,
                           groov::field<"pcsamplena", common::bit_enable, 12, 12>,
                           groov::field<"synctap", std::uint8_t, 11, 10>,
                           groov::field<"cyctap", bool, 9, 9>,
                           groov::field<"postinit", std::uint8_t, 8, 5>,
                           groov::field<"postpreset", std::uint8_t, 4, 1>,
                           groov::field<"cyccntena", common::bit_enable, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using cyccnt_tt = groov::reg<Name,
                             std::uint32_t,
                             Baseaddress + Offset,
                             common::access::rw,
                             groov::field<"cyccnt", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using cpicnt_tt = groov::reg<Name,
                             std::uint32_t,
                             Baseaddress + Offset,
                             common::access::rw,
                             groov::field<"reserved0", std::uint32_t, 31, 8, common::access::ro>,
                             groov::field<"cpicnt", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using exccnt_tt = groov::reg<Name,
                             std::uint32_t,
                             Baseaddress + Offset,
                             common::access::rw,
                             groov::field<"reserved0", std::uint32_t, 31, 8, common::access::ro>,
                             groov::field<"exccnt", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using sleepcnt_tt = groov::reg<Name,
                               std::uint32_t,
                               Baseaddress + Offset,
                               common::access::rw,
                               groov::field<"reserved0", std::uint32_t, 31, 8, common::access::ro>,
                               groov::field<"sleepcnt", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using lsucnt_tt = groov::reg<Name,
                             std::uint32_t,
                             Baseaddress + Offset,
                             common::access::rw,
                             groov::field<"reserved0", std::uint32_t, 31, 8, common::access::ro>,
                             groov::field<"lsucnt", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using foldcnt_tt = groov::reg<Name,
                              std::uint32_t,
                              Baseaddress + Offset,
                              common::access::rw,
                              groov::field<"reserved0", std::uint32_t, 31, 8, common::access::ro>,
                              groov::field<"foldcnt", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using pcsr_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::ro,
                           groov::field<"pcsr", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp0_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"comp0", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using mask0_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"mask0", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function0_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function0", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp1_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"comp1", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using mask1_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"mask1", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function1_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function1", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp2_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"comp2", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using mask2_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"mask2", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function2_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function2", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp3_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"comp3", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using mask3_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"mask3", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function3_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function3", std::uint32_t, 31, 0>>;

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
                          groov::field<"lsr", std::uint32_t, 31, 0>>;

template <std::uint32_t Baseaddress>
using dwt_t = groov::group<"dwt",
                           groov::mmio_bus<>,
                           ctrl_tt<"ctrl", Baseaddress, 0x0>,
                           cyccnt_tt<"cyccnt", Baseaddress, 0x4>,
                           cpicnt_tt<"cpicnt", Baseaddress, 0x8>,
                           exccnt_tt<"exccnt", Baseaddress, 0xc>,
                           sleepcnt_tt<"sleepcnt", Baseaddress, 0x10>,
                           lsucnt_tt<"lsucnt", Baseaddress, 0x14>,
                           foldcnt_tt<"foldcnt", Baseaddress, 0x18>,
                           pcsr_tt<"pcsr", Baseaddress, 0x1c>,
                           comp0_tt<"comp0", Baseaddress, 0x20>,
                           mask0_tt<"mask0", Baseaddress, 0x24>,
                           function0_tt<"function0", Baseaddress, 0x28>,
                           comp1_tt<"comp1", Baseaddress, 0x30>,
                           mask1_tt<"mask1", Baseaddress, 0x34>,
                           function1_tt<"function1", Baseaddress, 0x38>,
                           comp2_tt<"comp2", Baseaddress, 0x40>,
                           mask2_tt<"mask2", Baseaddress, 0x44>,
                           function2_tt<"function2", Baseaddress, 0x48>,
                           comp3_tt<"comp3", Baseaddress, 0x50>,
                           mask3_tt<"mask3", Baseaddress, 0x54>,
                           function3_tt<"function3", Baseaddress, 0x58>,
                           lar_tt<"lar", Baseaddress, 0xfb0>,
                           lsr_tt<"lsr", Baseaddress, 0xfb4>>;

inline constexpr std::uint32_t DWT_BASE = 0xE000'1000U;

} // namespace erworks::stm32::core::dwt

// NOLINTEND(*-magic-numbers)
