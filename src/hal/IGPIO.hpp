#pragma once

#include "core/Result.hpp"
#include "core/Status.hpp"
#include "core/Error.hpp"

namespace hal {

enum class GpioDirection { Input, Output };
enum class GpioState     { Low = 0, High = 1 };

class IGPIO {
public:
    virtual ~IGPIO() = default;

    [[nodiscard]] virtual core::Status                         configure(GpioDirection direction) noexcept = 0;
    [[nodiscard]] virtual core::Result<GpioState, core::Error> read()                      const noexcept = 0;
    [[nodiscard]] virtual core::Status                         write(GpioState state)             noexcept = 0;
    [[nodiscard]] virtual core::Status                         toggle()                           noexcept = 0;
};

} // namespace hal
