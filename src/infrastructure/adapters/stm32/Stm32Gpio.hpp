#pragma once

#include "hal/IGPIO.hpp"
// #include "stm32xxxx_hal.h"   ← uncomment and adapt for your STM32 family

namespace infrastructure::adapters::stm32 {

class Stm32Gpio final : public hal::IGPIO {
public:
    // Stm32Gpio(GPIO_TypeDef* port, uint16_t pin) noexcept;

    core::Status                             configure(hal::GpioDirection direction) noexcept override;
    core::Result<hal::GpioState, core::Error> read()                          const noexcept override;
    core::Status                             write(hal::GpioState state)             noexcept override;
    core::Status                             toggle()                                noexcept override;

private:
    // GPIO_TypeDef* port_{nullptr};
    // uint16_t      pin_{0};
};

} // namespace infrastructure::adapters::stm32
