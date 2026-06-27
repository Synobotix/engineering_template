#pragma once

#include "hal/IGPIO.hpp"

namespace infrastructure::adapters::mock {

class MockGpio final : public hal::IGPIO {
public:
    core::Status configure(hal::GpioDirection direction) noexcept override
    {
        last_direction = direction;
        return core::status::ok();
    }

    core::Result<hal::GpioState, core::Error> read() const noexcept override
    {
        return core::Result<hal::GpioState, core::Error>::ok(injected_state);
    }

    core::Status write(hal::GpioState state) noexcept override
    {
        last_written = state;
        ++write_count;
        return core::status::ok();
    }

    core::Status toggle() noexcept override
    {
        ++toggle_count;
        injected_state = (injected_state == hal::GpioState::Low)
                       ? hal::GpioState::High
                       : hal::GpioState::Low;
        return core::status::ok();
    }

    // Test inspection
    hal::GpioState     injected_state{hal::GpioState::Low};
    hal::GpioDirection last_direction{hal::GpioDirection::Output};
    hal::GpioState     last_written  {hal::GpioState::Low};
    int                write_count   {0};
    int                toggle_count  {0};
};

} // namespace infrastructure::adapters::mock
