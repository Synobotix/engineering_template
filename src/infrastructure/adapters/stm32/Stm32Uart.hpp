#pragma once

#include "hal/IUART.hpp"
// #include "stm32xxxx_hal.h"   ← uncomment and adapt for your STM32 family

namespace infrastructure::adapters::stm32 {

class Stm32Uart final : public hal::IUART {
public:
    // explicit Stm32Uart(UART_HandleTypeDef* handle) noexcept;

    core::Status                               configure(const hal::UartConfig& config)            noexcept override;
    core::Status                               write(const uint8_t* data, std::size_t length)      noexcept override;
    core::Result<std::size_t, core::Error>      read(uint8_t* buffer, std::size_t max_length)      noexcept override;
    bool                                       is_data_available()                          const  noexcept override;

private:
    // UART_HandleTypeDef* handle_{nullptr};
};

} // namespace infrastructure::adapters::stm32
