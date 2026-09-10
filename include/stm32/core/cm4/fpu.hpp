#pragma once

#include <groov/groov.hpp>

#include "../../common/access.hpp"
#include "../../common/bittypes.hpp"

// NOLINTBEGIN(*-magic-numbers)
namespace erworks::stm32::core::fpu {

  template <stdx::ct_string Name,
            std::uint32_t   Baseaddress,
            std::uint32_t   Offset>
  using fpccr_tt = groov::reg<Name,
                              std::uint32_t,
                              Baseaddress + Offset,
                              common::access::rw,
                              groov::field<"aspen", common::bit_enable, 31, 31>,
                              groov::field<"lspen", common::bit_enable, 30, 30>,
                              groov::field<"reserved2", std::uint32_t, 29, 9, common::access::ro>,
                              groov::field<"monrdy", common::bit_ready, 8, 8>,
                              groov::field<"reserved1", bool, 7, 7, common::access::ro>,
                              groov::field<"bfrdy", common::bit_ready, 6, 6>,
                              groov::field<"mmrdy", common::bit_ready, 5, 5>,
                              groov::field<"hfrdy", common::bit_ready, 4, 4>,
                              groov::field<"thread", bool, 3, 3>,
                              groov::field<"reserved0", bool, 2, 2, common::access::ro>,
                              groov::field<"user", bool, 1, 1>,
                              groov::field<"lspact", bool, 0, 0>>;

  template <stdx::ct_string Name,
            std::uint32_t   Baseaddress,
            std::uint32_t   Offset>
  using fpcar_tt = groov::reg<Name,
                              std::uint32_t,
                              Baseaddress + Offset,
                              common::access::rw,
                              groov::field<"address", std::uint32_t, 31, 3>,
                              groov::field<"reserved0", std::uint8_t, 2, 0, common::access::ro>>;

  template <stdx::ct_string Name,
            std::uint32_t   Baseaddress,
            std::uint32_t   Offset>
  using fpdscr_tt = groov::reg<Name,
                               std::uint32_t,
                               Baseaddress + Offset,
                               common::access::rw,
                               groov::field<"reserved1", std::uint8_t, 31, 27, common::access::ro>,
                               groov::field<"ahp", bool, 26, 26>,
                               groov::field<"dn", bool, 25, 25>,
                               groov::field<"fz", bool, 24, 24>,
                               groov::field<"rmode", std::uint8_t, 23, 22>,
                               groov::field<"reserved0", std::uint32_t, 21, 0, common::access::ro>>;

  template <stdx::ct_string Name,
            std::uint32_t   Baseaddress,
            std::uint32_t   Offset>
  using mvfr0_tt =
    groov::reg<Name,
               std::uint32_t,
               Baseaddress + Offset,
               common::access::ro,
               groov::field<"fp_rounding_modes", std::uint8_t, 31, 28>,
               groov::field<"short_vectors", std::uint8_t, 27, 24>,
               groov::field<"square_root", std::uint8_t, 23, 20>,
               groov::field<"divide", std::uint8_t, 19, 16>,
               groov::field<"fp_excep_trapping", std::uint8_t, 15, 12>,
               groov::field<"double_precision", std::uint8_t, 11, 8>,
               groov::field<"single_precision", std::uint8_t, 7, 4>,
               groov::field<"a_simd_registers", std::uint8_t, 3, 0>>;

  template <stdx::ct_string Name,
            std::uint32_t   Baseaddress,
            std::uint32_t   Offset>
  using mvfr1_tt =
    groov::reg<Name,
               std::uint32_t,
               Baseaddress + Offset,
               common::access::ro,
               groov::field<"fp_fused_mac", std::uint8_t, 31, 28>,
               groov::field<"fp_hpfp", std::uint8_t, 27, 24>,
               groov::field<"reserved0", std::uint16_t, 23, 8, common::access::ro>,
               groov::field<"d_nan_mode", std::uint8_t, 7, 4>,
               groov::field<"ftz_mode", std::uint8_t, 3, 0>>;

  template <stdx::ct_string Name,
            std::uint32_t   Baseaddress,
            std::uint32_t   Offset>
  using mvfr2_tt = groov::reg<Name,
                              std::uint32_t,
                              Baseaddress + Offset,
                              common::access::ro,
                              groov::field<"reserved1", std::uint32_t, 31, 8, common::access::ro>,
                              groov::field<"vfp_misc", std::uint8_t, 7, 4>,
                              groov::field<"reserved0", std::uint8_t, 3, 0, common::access::ro>>;

  template <std::uint32_t Baseaddress>
  using fpu_t = groov::group<"fpu",
                             groov::mmio_bus<>,
                             fpccr_tt<"fpccr", Baseaddress, 0x4>,
                             fpcar_tt<"fpcar", Baseaddress, 0x8>,
                             fpdscr_tt<"fpdscr", Baseaddress, 0xc>,
                             mvfr0_tt<"mvfr0", Baseaddress, 0x10>,
                             mvfr1_tt<"mvfr1", Baseaddress, 0x14>,
                             mvfr2_tt<"mvfr2", Baseaddress, 0x18>>;

  inline constexpr std::uint32_t FPU_BASE = 0xE000'EF30U;

} // namespace erworks::stm32::core::fpu

// NOLINTEND(*-magic-numbers)
