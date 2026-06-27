#pragma once

#include <cstdint>

namespace core {

class IWatchdog {
public:
    virtual ~IWatchdog() = default;

    [[nodiscard]] virtual bool start(uint32_t timeout_ms) noexcept = 0;
    virtual void               kick()                     noexcept = 0;
    virtual void               stop()                     noexcept = 0;
};

} // namespace core
