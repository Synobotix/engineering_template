#pragma once

#include "hal/IGPIO.hpp"
#include <cstdint>

namespace infrastructure::adapters::posix {

// GPIO via Linux sysfs (/sys/class/gpio)
class PosixGpio final : public hal::IGPIO {
public:
    explicit PosixGpio(uint32_t gpio_number) noexcept;
    ~PosixGpio() override;

    core::Status                              configure(hal::GpioDirection direction) noexcept override;
    core::Result<hal::GpioState, core::Error> read()                          const  noexcept override;
    core::Status                              write(hal::GpioState state)             noexcept override;
    core::Status                              toggle()                                noexcept override;

private:
    uint32_t gpio_number_;
    int      value_fd_{-1};
};

} // namespace infrastructure::adapters::posix
