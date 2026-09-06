#pragma once

#include <groov/groov.hpp>

#include "../../common/access.hpp"
#include "../../common/bittypes.hpp"

namespace erworks::stm32::core {
  namespace systic {

    template <stdx:ct_string name,
             std::uint32_t baseaddress,
             std::uint32_t offset>
    using ctrl_tt = groov::reg<name,
    std::uint32_t,
    baseaddress + offset,
    common::access::rw,
    groov::field<"countflag", bool, 16, 16>,
    groov::field<"clksource", bool, 2, 2>,
    groov::field<"tickint", bool, 1, 1>,
    groov::field<"enable", bool, 0,0>>;
  }
}
