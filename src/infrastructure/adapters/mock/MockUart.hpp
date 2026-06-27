#pragma once

#include "hal/IUART.hpp"
#include <array>
#include <cstring>

namespace infrastructure::adapters::mock {

class MockUart final : public hal::IUART {
public:
    core::Status configure(const hal::UartConfig& config) noexcept override
    {
        last_config = config;
        return core::status::ok();
    }

    core::Status write(const uint8_t* data, std::size_t length) noexcept override
    {
        std::size_t to_copy = (length < tx_buffer.size()) ? length : tx_buffer.size();
        std::memcpy(tx_buffer.data(), data, to_copy);
        tx_length = to_copy;
        ++write_count;
        return core::status::ok();
    }

    core::Result<std::size_t, core::Error> read(uint8_t* buffer, std::size_t max_length) noexcept override
    {
        std::size_t to_copy = (rx_length < max_length) ? rx_length : max_length;
        std::memcpy(buffer, rx_buffer.data(), to_copy);
        return core::Result<std::size_t, core::Error>::ok(to_copy);
    }

    bool is_data_available() const noexcept override { return rx_length > 0; }

    // Test inspection / injection
    hal::UartConfig                last_config{};
    std::array<uint8_t, 256>       tx_buffer{};
    std::size_t                    tx_length{0};
    std::array<uint8_t, 256>       rx_buffer{};
    std::size_t                    rx_length{0};
    int                            write_count{0};
};

} // namespace infrastructure::adapters::mock
