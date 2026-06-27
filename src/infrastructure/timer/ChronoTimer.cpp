#include "infrastructure/timer/ChronoTimer.hpp"

namespace infrastructure::timer {

uint64_t ChronoClock::now_ms() const noexcept
{
    using namespace std::chrono;
    return static_cast<uint64_t>(
        duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count());
}

void ChronoTimer::start(uint32_t duration_ms) noexcept
{
    start_time_  = Clock::now();
    duration_ms_ = duration_ms;
    running_     = true;
}

void ChronoTimer::stop() noexcept { running_ = false; }

void ChronoTimer::reset() noexcept
{
    start_time_ = Clock::now();
}

bool ChronoTimer::is_expired() const noexcept
{
    if (!running_) return false;
    return elapsed_ms() >= duration_ms_;
}

uint32_t ChronoTimer::elapsed_ms() const noexcept
{
    using namespace std::chrono;
    return static_cast<uint32_t>(
        duration_cast<milliseconds>(Clock::now() - start_time_).count());
}

} // namespace infrastructure::timer
