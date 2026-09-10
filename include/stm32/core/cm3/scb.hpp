#pragma once

#include <groov/groov.hpp>

#include "../../common/access.hpp"
#include "../../common/bittypes.hpp"

// NOLINTBEGIN(*-magic-numbers)
namespace erworks::stm32::core::scb {

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
using icsr_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::rw,
                           groov::field<"nmipendset", bool, 31, 31>,
                           groov::field<"reserved3", std::uint8_t, 30, 29, common::access::ro>,
                           groov::field<"pendsvset", bool, 28, 28>,
                           groov::field<"pendsvclr", bool, 27, 27>,
                           groov::field<"pendstset", bool, 26, 26>,
                           groov::field<"pendstclr", bool, 25, 25>,
                           groov::field<"reserved2", bool, 24, 24, common::access::ro>,
                           groov::field<"isrpreempt", bool, 23, 23>,
                           groov::field<"isrpending", bool, 22, 22>,
                           groov::field<"reserved1", bool, 21, 21, common::access::ro>,
                           groov::field<"vectpending", std::uint16_t, 20, 12>,
                           groov::field<"rettobase", bool, 11, 11>,
                           groov::field<"reserved0", std::uint8_t, 10, 9, common::access::ro>,
                           groov::field<"vectactive", std::uint16_t, 8, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using vtor_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::rw,
                           groov::field<"tbloff", std::uint32_t, 31, 7>,
                           groov::field<"reserved0", std::uint8_t, 6, 0, common::access::ro>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using aircr_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"vectkey", std::uint16_t, 31, 16>,
                            groov::field<"vectkeystat", std::uint16_t, 31, 16>,
                            groov::field<"endianess", bool, 15, 15>,
                            groov::field<"reserved1", std::uint8_t, 14, 11, common::access::ro>,
                            groov::field<"prigroup", std::uint8_t, 10, 8>,
                            groov::field<"reserved0", std::uint8_t, 7, 3, common::access::ro>,
                            groov::field<"sysresetreq", bool, 2, 2>,
                            groov::field<"vectclractive", bool, 1, 1>,
                            groov::field<"vectreset", bool, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using scr_tt = groov::reg<Name,
                          std::uint32_t,
                          Baseaddress + Offset,
                          common::access::rw,
                          groov::field<"reserved2", std::uint32_t, 31, 5, common::access::ro>,
                          groov::field<"sevonpend", bool, 4, 4>,
                          groov::field<"reserved1", bool, 3, 3, common::access::ro>,
                          groov::field<"sleepdeep", bool, 2, 2>,
                          groov::field<"sleeponexit", bool, 1, 1>,
                          groov::field<"reserved0", bool, 0, 0, common::access::ro>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using ccr_tt = groov::reg<Name,
                          std::uint32_t,
                          Baseaddress + Offset,
                          common::access::rw,
                          groov::field<"reserved2", std::uint32_t, 31, 10, common::access::ro>,
                          groov::field<"stkalign", bool, 9, 9>,
                          groov::field<"bfhfnmign", bool, 8, 8>,
                          groov::field<"reserved1", std::uint8_t, 7, 5, common::access::ro>,
                          groov::field<"div_0_trp", bool, 4, 4>,
                          groov::field<"unalign_trp", bool, 3, 3>,
                          groov::field<"reserved0", bool, 2, 2, common::access::ro>,
                          groov::field<"usersetmpend", bool, 1, 1>,
                          groov::field<"nonbasethrdena", bool, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using shcsr_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"reserved3", std::uint16_t, 31, 19, common::access::ro>,
                            groov::field<"usgfaultena", bool, 18, 18>,
                            groov::field<"busfaultena", bool, 17, 17>,
                            groov::field<"memfaultena", bool, 16, 16>,
                            groov::field<"svcallpended", bool, 15, 15>,
                            groov::field<"busfaultpended", bool, 14, 14>,
                            groov::field<"memfaultpended", bool, 13, 13>,
                            groov::field<"usgfaultpended", bool, 12, 12>,
                            groov::field<"systickact", bool, 11, 11>,
                            groov::field<"pendsvact", bool, 10, 10>,
                            groov::field<"reserved2", bool, 9, 9, common::access::ro>,
                            groov::field<"monitoract", bool, 8, 8>,
                            groov::field<"svcallact", bool, 7, 7>,
                            groov::field<"reserved1", std::uint8_t, 6, 4, common::access::ro>,
                            groov::field<"usgfaultact", bool, 3, 3>,
                            groov::field<"reserved0", bool, 2, 2, common::access::ro>,
                            groov::field<"busfaultact", bool, 1, 1>,
                            groov::field<"memfaultact", bool, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using cfsr_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::rw,
                           groov::field<"usgfaultsr", std::uint16_t, 31, 16>,
                           groov::field<"busfaultsr", std::uint8_t, 15, 8>,
                           groov::field<"memfaultsr", std::uint8_t, 7, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using hfsr_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::rw,
                           groov::field<"debugevt", bool, 31, 31>,
                           groov::field<"forced", bool, 30, 30>,
                           groov::field<"reserved1", std::uint32_t, 29, 2, common::access::ro>,
                           groov::field<"vecttbl", bool, 1, 1>,
                           groov::field<"reserved0", bool, 0, 0, common::access::ro>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using dfsr_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::rw,
                           groov::field<"reserved0", std::uint32_t, 31, 5, common::access::ro>,
                           groov::field<"external", bool, 4, 4>,
                           groov::field<"vcatch", bool, 3, 3>,
                           groov::field<"dwttrap", bool, 2, 2>,
                           groov::field<"bkpt", bool, 1, 1>,
                           groov::field<"halted", bool, 0, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using mmfar_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"mmfar", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using bfar_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::rw,
                           groov::field<"bfar", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using afsr_tt = groov::reg<Name,
                           std::uint32_t,
                           Baseaddress + Offset,
                           common::access::rw,
                           groov::field<"afsr", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using dfr_tt = groov::reg<Name,
                          std::uint32_t,
                          Baseaddress + Offset,
                          common::access::ro,
                          groov::field<"dfr", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using adr_tt = groov::reg<Name,
                          std::uint32_t,
                          Baseaddress + Offset,
                          common::access::ro,
                          groov::field<"adr", std::uint32_t, 31, 0>>;

template <stdx::ct_string Name, std::uint32_t Baseaddress, std::uint32_t Offset>
using cpacr_tt = groov::reg<Name,
                            std::uint32_t,
                            Baseaddress + Offset,
                            common::access::rw,
                            groov::field<"cpacr", std::uint32_t, 31, 0>>;

template <std::uint32_t Baseaddress>
using scb_t = groov::group<"scb",
                           groov::mmio_bus<>,
                           cpuid_tt<"cpuid", Baseaddress, 0x0>,
                           icsr_tt<"icsr", Baseaddress, 0x4>,
                           vtor_tt<"vtor", Baseaddress, 0x8>,
                           aircr_tt<"aircr", Baseaddress, 0xc>,
                           scr_tt<"scr", Baseaddress, 0x10>,
                           ccr_tt<"ccr", Baseaddress, 0x14>,
                           shcsr_tt<"shcsr", Baseaddress, 0x24>,
                           cfsr_tt<"cfsr", Baseaddress, 0x28>,
                           hfsr_tt<"hfsr", Baseaddress, 0x2c>,
                           dfsr_tt<"dfsr", Baseaddress, 0x30>,
                           mmfar_tt<"mmfar", Baseaddress, 0x34>,
                           bfar_tt<"bfar", Baseaddress, 0x38>,
                           afsr_tt<"afsr", Baseaddress, 0x3c>,
                           dfr_tt<"dfr", Baseaddress, 0x48>,
                           adr_tt<"adr", Baseaddress, 0x4c>,
                           cpacr_tt<"cpacr", Baseaddress, 0x88>>;

inline constexpr std::uint32_t SCB_BASE = 0xE000'ED00U;

} // namespace erworks::stm32::core::scb
  // NOLINTEND(*-magic-numbers)
