#pragma once

#include "core/IWatchdog.hpp"

namespace infrastructure::watchdog {

// Hardware watchdog via Linux /dev/watchdog.
// Requires CAP_SYS_BOOT or root privileges.
class PosixWatchdog final : public core::IWatchdog {
public:
    explicit PosixWatchdog(const char* device = "/dev/watchdog") noexcept;
    ~PosixWatchdog() override;

    bool start(uint32_t timeout_ms) noexcept override;
    void kick()                     noexcept override;
    void stop()                     noexcept override;

private:
    const char* device_;
    int         fd_{-1};
};

} // namespace infrastructure::watchdog
