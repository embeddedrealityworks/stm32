#pragma once

#include "cm33/coredebug.hpp"
#include "cm33/dcb.hpp"
#include "cm33/dwt.hpp"
#include "cm33/fpu.hpp"
#include "cm33/itm.hpp"
#include "cm33/mpu.hpp"
#include "cm33/sau.hpp"
#include "cm33/scb.hpp"
#include "cm33/systick.hpp"

namespace erworks::stm32 {
inline constexpr auto coredebug =
  core::coredebug::coredebug_t<core::coredebug::COREDEBUG_BASE>{};
inline constexpr auto dcb = core::dcb::dcb_t<core::dcb::DCB_BASE>{};
inline constexpr auto dwt = core::dwt::dwt_t<core::dwt::DWT_BASE>{};
inline constexpr auto fpu = core::fpu::fpu_t<core::fpu::FPU_BASE>{};
inline constexpr auto itm = core::itm::itm_t<core::itm::ITM_BASE>{};
inline constexpr auto mpu = core::mpu::mpu_t<core::mpu::MPU_BASE>{};
inline constexpr auto sau = core::sau::sau_t<core::sau::SAU_BASE>{};
inline constexpr auto scb = core::scb::scb_t<core::scb::SCB_BASE>{};
inline constexpr auto systick =
  core::systick::systick_t<core::systick::SYSTICK_BASE>{};
} // namespace erworks::stm32
