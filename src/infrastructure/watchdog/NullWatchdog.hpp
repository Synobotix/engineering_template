#pragma once

#include "core/IWatchdog.hpp"

namespace infrastructure::watchdog {

class NullWatchdog final : public core::IWatchdog {
public:
    bool start(uint32_t) noexcept override { return true; }
    void kick()          noexcept override {}
    void stop()          noexcept override {}
};

} // namespace infrastructure::watchdog
