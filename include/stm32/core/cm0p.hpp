#pragma once

#include "cm0p/systick.hpp"
#include "cm0p/scb.hpp"
#include "cm0p/mpu.hpp"

namespace erworks::stm32 {

  inline constexpr auto systick = core::systick::systick_t<core::systick::SYSTICK_BASE>{};
  inline constexpr auto scb = core::scb::scb_t<core::scb::SCB_BASE>{};
  inline constexpr auto mpu = core::mpu::mpu_t<core::mpu::MPU_BASE>{};
}
