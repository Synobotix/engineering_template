#pragma once

#include "core/IClock.hpp"
#include <cstddef>
#include <cstdint>

namespace core {

// Token-bucket rate limiter — header-only, no heap.
// RateHz  : maximum events per second
// BurstN  : maximum burst size (token bucket capacity)
template<std::size_t RateHz, std::size_t BurstN = RateHz>
class RateLimiter {
    static_assert(RateHz > 0, "RateHz must be > 0");
    static_assert(BurstN > 0, "BurstN must be > 0");

public:
    explicit RateLimiter(IClock& clock) noexcept
        : clock_(clock)
        , last_ms_(clock.now_ms())
        , tokens_(BurstN)
    {}

    [[nodiscard]] bool allow() noexcept
    {
        refill();
        if (tokens_ == 0) return false;
        --tokens_;
        return true;
    }

    [[nodiscard]] std::size_t available_tokens() const noexcept { return tokens_; }

private:
    void refill() noexcept
    {
        uint64_t    now     = clock_.now_ms();
        uint64_t    elapsed = now - last_ms_;
        std::size_t earned  = static_cast<std::size_t>(elapsed * RateHz / 1000u);
        if (earned == 0) return;
        tokens_  = (tokens_ + earned > BurstN) ? BurstN : tokens_ + earned;
        last_ms_ = now;
    }

    IClock&     clock_;
    uint64_t    last_ms_;
    std::size_t tokens_;
};

} // namespace core
