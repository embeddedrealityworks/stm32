#pragma once

#include "cm0/scb.hpp"
#include "cm0/systick.hpp"

namespace erworks::stm32 {

inline constexpr auto          systick =
  core::systick::systick_t<core::systick::SYSTICK_BASE>{};
inline constexpr auto scb = core::scb::scb_t<core::scb::SCB_BASE>{};

} // namespace erworks::stm32
