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
                           groov::field<"cycdiss", bool, 23, 23>,
                           groov::field<"cycevtena", bool, 22, 22>,
                           groov::field<"foldevtena", bool, 21, 21>,
                           groov::field<"lsuevtena", bool, 20, 20>,
                           groov::field<"sleepevtena", bool, 19, 19>,
                           groov::field<"excevtena", bool, 18, 18>,
                           groov::field<"cpievtena", bool, 17, 17>,
                           groov::field<"exctrcena", bool, 16, 16>,
                           groov::field<"pcsamplena", bool, 12, 12>,
                           groov::field<"synctap", std::uint8_t, 11, 10>,
                           groov::field<"cyctap", bool, 9, 9>,
                           groov::field<"postinit", std::uint8_t, 8, 5>,
                           groov::field<"postpreset", std::uint8_t, 4, 1>,
                           groov::field<"cyccntena", bool, 0, 0>>;

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
                             groov::field<"cpicnt", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using exccnt_tt = groov::reg<Name,
                             std::uint32_t,
                             Baseaddress + Offset,
                             common::access::rw,
                             groov::field<"exccnt", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using sleepcnt_tt = groov::reg<Name,
                               std::uint32_t,
                               Baseaddress + Offset,
                               common::access::rw,
                               groov::field<"sleepcnt", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using lsucnt_tt = groov::reg<Name,
                             std::uint32_t,
                             Baseaddress + Offset,
                             common::access::rw,
                             groov::field<"lsucnt", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using foldcnt_tt = groov::reg<Name,
                              std::uint32_t,
                              Baseaddress + Offset,
                              common::access::rw,
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
using function3_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function3", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp4_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"comp4", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function4_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function4", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp5_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"comp5", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function5_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function5", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp6_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"comp6", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function6_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function6", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp7_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"comp7", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function7_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function7", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp8_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"comp8", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function8_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function8", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp9_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"comp9", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function9_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function9", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp10_tt = groov::reg<Name,
                             std::uint32_t,
                             Baseaddress + Offset,
                             common::access::rw,
                             groov::field<"comp10", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function10_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function10", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp11_tt = groov::reg<Name,
                             std::uint32_t,
                             Baseaddress + Offset,
                             common::access::rw,
                             groov::field<"comp11", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function11_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function11", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp12_tt = groov::reg<Name,
                             std::uint32_t,
                             Baseaddress + Offset,
                             common::access::rw,
                             groov::field<"comp12", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function12_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function12", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp13_tt = groov::reg<Name,
                             std::uint32_t,
                             Baseaddress + Offset,
                             common::access::rw,
                             groov::field<"comp13", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function13_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function13", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp14_tt = groov::reg<Name,
                             std::uint32_t,
                             Baseaddress + Offset,
                             common::access::rw,
                             groov::field<"comp14", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function14_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function14", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using comp15_tt = groov::reg<Name,
                             std::uint32_t,
                             Baseaddress + Offset,
                             common::access::rw,
                             groov::field<"comp15", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using function15_tt =
  groov::reg<Name,
             std::uint32_t,
             Baseaddress + Offset,
             common::access::rw,
             groov::field<"function15", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using lsr_tt = groov::reg<Name,
                          std::uint32_t,
                          Baseaddress + Offset,
                          common::access::ro,
                          groov::field<"lsr", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using devarch_tt = groov::reg<Name,
                              std::uint32_t,
                              Baseaddress + Offset,
                              common::access::ro,
                              groov::field<"devarch", std::uint32_t, 31, 0>>;

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
                           function0_tt<"function0", Baseaddress, 0x28>,
                           comp1_tt<"comp1", Baseaddress, 0x30>,
                           function1_tt<"function1", Baseaddress, 0x38>,
                           comp2_tt<"comp2", Baseaddress, 0x40>,
                           function2_tt<"function2", Baseaddress, 0x48>,
                           comp3_tt<"comp3", Baseaddress, 0x50>,
                           function3_tt<"function3", Baseaddress, 0x58>,
                           comp4_tt<"comp4", Baseaddress, 0x60>,
                           function4_tt<"function4", Baseaddress, 0x68>,
                           comp5_tt<"comp5", Baseaddress, 0x70>,
                           function5_tt<"function5", Baseaddress, 0x78>,
                           comp6_tt<"comp6", Baseaddress, 0x80>,
                           function6_tt<"function6", Baseaddress, 0x88>,
                           comp7_tt<"comp7", Baseaddress, 0x90>,
                           function7_tt<"function7", Baseaddress, 0x98>,
                           comp8_tt<"comp8", Baseaddress, 0xa0>,
                           function8_tt<"function8", Baseaddress, 0xa8>,
                           comp9_tt<"comp9", Baseaddress, 0xb0>,
                           function9_tt<"function9", Baseaddress, 0xb8>,
                           comp10_tt<"comp10", Baseaddress, 0xc0>,
                           function10_tt<"function10", Baseaddress, 0xc8>,
                           comp11_tt<"comp11", Baseaddress, 0xd0>,
                           function11_tt<"function11", Baseaddress, 0xd8>,
                           comp12_tt<"comp12", Baseaddress, 0xe0>,
                           function12_tt<"function12", Baseaddress, 0xe8>,
                           comp13_tt<"comp13", Baseaddress, 0xf0>,
                           function13_tt<"function13", Baseaddress, 0xf8>,
                           comp14_tt<"comp14", Baseaddress, 0x100>,
                           function14_tt<"function14", Baseaddress, 0x108>,
                           comp15_tt<"comp15", Baseaddress, 0x110>,
                           function15_tt<"function15", Baseaddress, 0x118>,
                           lsr_tt<"lsr", Baseaddress, 0xfb4>,
                           devarch_tt<"devarch", Baseaddress, 0xfbc>>;

inline constexpr std::uint32_t DWT_BASE = 0xE000'1000U;

} // namespace erworks::stm32::core::dwt

// NOLINTEND(*-magic-numbers)
