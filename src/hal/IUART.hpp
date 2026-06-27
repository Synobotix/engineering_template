#pragma once

#include "core/Result.hpp"
#include "core/Status.hpp"
#include "core/Error.hpp"
#include <cstddef>
#include <cstdint>

namespace hal {

enum class UartBaudRate : uint32_t {
    k9600   =   9600,
    k19200  =  19200,
    k38400  =  38400,
    k115200 = 115200,
};

struct UartConfig {
    UartBaudRate baud_rate = UartBaudRate::k115200;
    uint8_t      data_bits = 8;
    uint8_t      stop_bits = 1;
    bool         parity    = false;
};

class IUART {
public:
    virtual ~IUART() = default;

    [[nodiscard]] virtual core::Status                              configure(const UartConfig& config)              noexcept = 0;
    [[nodiscard]] virtual core::Status                              write(const uint8_t* data, std::size_t length)   noexcept = 0;
    [[nodiscard]] virtual core::Result<std::size_t, core::Error>   read(uint8_t* buffer, std::size_t max_length)    noexcept = 0;
    [[nodiscard]] virtual bool                                      is_data_available()                       const  noexcept = 0;
};

} // namespace hal
