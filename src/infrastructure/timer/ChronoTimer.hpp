#pragma once

#include "core/IClock.hpp"
#include "core/ITimer.hpp"
#include <chrono>

namespace infrastructure::timer {

class ChronoClock final : public core::IClock {
public:
    uint64_t now_ms() const noexcept override;
};

class ChronoTimer final : public core::ITimer {
public:
    void     start(uint32_t duration_ms) noexcept override;
    void     stop()                      noexcept override;
    bool     is_expired()          const noexcept override;
    void     reset()                     noexcept override;
    uint32_t elapsed_ms()          const noexcept override;

private:
    using Clock = std::chrono::steady_clock;
    Clock::time_point start_time_{};
    uint32_t          duration_ms_{0};
    bool              running_{false};
};

} // namespace infrastructure::timer
