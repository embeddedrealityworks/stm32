#pragma once

#include "cm0/systick.hpp"
#include "cm0/scb.hpp"

namespace erworks::stm::core {
inline constexpr auto systic = systick::systic_t<systick::SYSTICK_BASE>{};
inline constexpr auto scb = scb::scb_t<scb::SCB_BASE>{}
}
