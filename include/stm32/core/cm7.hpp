#pragma once

#include "cm7/systick.hpp"
#include "cm7/scb.hpp"
#include "cm7/mpu.hpp"
#include "cm7/fpu.hpp"
#include "cm7/coredebug.hpp"
#include "cm7/dwt.hpp"
#include "cm7/itm.hpp"

namespace erworks::stm32 {

  inline constexpr auto systick = core::systick::systick_t<core::systick::SYSTICK_BASE>{};
  inline constexpr auto scb = core::scb::scb_t<core::scb::SCB_BASE>{};
  inline constexpr auto mpu = core::mpu::mpu_t<core::mpu::MPU_BASE>{};
  inline constexpr auto fpu = core::fpu::fpu_t<core::fpu::FPU_BASE>{};
  inline constexpr auto coredebug = core::coredebug::coredebug_t<core::coredebug::COREDEBUG_BASE>{};
  inline constexpr auto dwt = core::dwt::dwt_t<core::dwt::DWT_BASE>{};
  inline constexpr auto itm = core::itm::itm_t<core::itm::ITM_BASE>{};
}
