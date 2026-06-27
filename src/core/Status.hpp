#pragma once

#include "core/Result.hpp"
#include "core/Error.hpp"

namespace core {

struct Ok {};
using Status = Result<Ok, Error>;

namespace status {
    inline Status ok()         noexcept { return Status::ok(Ok{});  }
    inline Status err(Error e) noexcept { return Status::err(e);    }
} // namespace status

} // namespace core
