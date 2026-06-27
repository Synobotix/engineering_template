#pragma once

#include "hal/IUART.hpp"
#include <string_view>

namespace infrastructure::adapters::posix {

// UART via termios (/dev/ttyS*, /dev/ttyUSB*, /dev/ttyAMA*)
class PosixUart final : public hal::IUART {
public:
    explicit PosixUart(std::string_view device_path) noexcept;
    ~PosixUart() override;

    core::Status                               configure(const hal::UartConfig& config)           noexcept override;
    core::Status                               write(const uint8_t* data, std::size_t length)     noexcept override;
    core::Result<std::size_t, core::Error>      read(uint8_t* buffer, std::size_t max_length)     noexcept override;
    bool                                       is_data_available()                         const  noexcept override;

private:
    char device_path_[64]{};
    int  fd_{-1};
};

} // namespace infrastructure::adapters::posix
