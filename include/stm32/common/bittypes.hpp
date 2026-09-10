#pragma once

#include <groov/groov.hpp>

namespace erworks::stm32::common {

// NOLINTBEGIN(*-identifier-naming)
enum class bit_enable : bool {
  ENABLED  = true,
  DISABLED = false,
  ON       = true,
  OFF      = false,
  one      = true,
  zero     = false,
};

enum class bit_nenable : bool {
  ENABLED  = false,
  DISABLED = true,
  ON       = false,
  OFF      = true,
  zero     = false,
  one      = true,
};

enum class bit_ready : bool {
  READY     = true,
  NOT_READY = false,
  zero      = false,
  one       = true,
};

enum class bit_nready : bool {
  READY     = false,
  NOT_READY = true,
  zero      = false,
  one       = true,
};

enum class bit_locked : bool {
  LOCKED   = true,
  UNLOCKED = false,
  zero     = false,
  one      = true,
};

enum class bit_nlocked : bool {
  LOCKED   = false,
  UNLOCKED = true,
  zero     = false,
  one      = true,
};

enum class bit_reset : bool {
  do_nothing = false,
  RESET      = true,
  SET        = true,
  zero       = false,
  one        = true,
};

} // namespace erworks::stm32::common
  // NOLINTEND(*-identifier-naming)
