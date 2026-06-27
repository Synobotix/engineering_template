#pragma once

#include <cstdint>

namespace core {

class ITimer {
public:
    virtual ~ITimer() = default;

    virtual void              start(uint32_t duration_ms) noexcept = 0;
    virtual void              stop()                      noexcept = 0;
    [[nodiscard]] virtual bool     is_expired()      const noexcept = 0;
    virtual void              reset()                     noexcept = 0;
    [[nodiscard]] virtual uint32_t elapsed_ms()      const noexcept = 0;
};

} // namespace core
