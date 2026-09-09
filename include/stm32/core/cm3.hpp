#pragma once

#include "cm3/coredebug.hpp"
#include "cm3/dwt.hpp"
#include "cm3/itm.hpp"
#include "cm3/mpu.hpp"
#include "cm3/scb.hpp"
#include "cm3/systick.hpp"

namespace erworks::stm32 {
inline constexpr auto systick =
  core::systick::systick_t<core::systick::SYSTICK_BASE>{};
inline constexpr auto scb = core::scb::scb_t<core::scb::SCB_BASE>{};
inline constexpr auto mpu = core::mpu::mpu_t<core::mpu::MPU_BASE>{};
inline constexpr auto itm = core::itm::itm_t<core::itm::ITM_BASE>{};
inline constexpr auto dwt = core::dwt::dwt_t<core::dwt::DWT_BASE>{};
inline constexpr auto coredebug =
  core::coredebug::coredebug_t<core::coredebug::COREDEBUG_BASE>{};
} // namespace erworks::stm32
