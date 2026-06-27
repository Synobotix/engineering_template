#pragma once

#include "core/IClock.hpp"

namespace test {

class MockClock final : public core::IClock {
public:
    explicit MockClock(uint64_t initial_ms = 0) noexcept : now_(initial_ms) {}

    uint64_t now_ms() const noexcept override { return now_; }

    void advance(uint64_t ms) noexcept { now_ += ms; }
    void set_time(uint64_t ms) noexcept { now_ = ms; }

private:
    uint64_t now_;
};

} // namespace test
