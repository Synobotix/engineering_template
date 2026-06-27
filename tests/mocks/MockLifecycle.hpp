#pragma once

#include "core/ILifecycle.hpp"

namespace test {

// Simulates a lifecycle that starts successfully and runs for `ticks` iterations
// before is_running() returns false.
class MockLifecycle final : public core::ILifecycle {
public:
    explicit MockLifecycle(bool start_ok = true, int ticks = 0) noexcept
        : start_ok_(start_ok)
        , ticks_remaining_(ticks)
    {}

    bool start() noexcept override
    {
        started_ = true;
        running_ = start_ok_;
        return start_ok_;
    }

    void stop() noexcept override
    {
        running_ = false;
        stopped_ = true;
    }

    bool is_running() const noexcept override
    {
        if (!running_) return false;
        if (ticks_remaining_ > 0) { --ticks_remaining_; return true; }
        running_ = false;
        return false;
    }

    bool started() const noexcept { return started_; }
    bool stopped() const noexcept { return stopped_; }

private:
    bool         start_ok_;
    mutable int  ticks_remaining_;
    bool         started_{false};
    bool         stopped_{false};
    mutable bool running_{false};
};

} // namespace test
