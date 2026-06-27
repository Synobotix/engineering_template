#include "infrastructure/lifecycle/SignalLifecycle.hpp"
#include <csignal>

namespace infrastructure::lifecycle {

namespace {
    volatile std::sig_atomic_t g_running{0};
    void signal_handler(int) noexcept { g_running = 0; }
}

bool SignalLifecycle::start() noexcept
{
    std::signal(SIGINT,  signal_handler);
    std::signal(SIGTERM, signal_handler);
    g_running = 1;
    return true;
}

void SignalLifecycle::stop()             noexcept { g_running = 0; }
bool SignalLifecycle::is_running() const noexcept { return g_running != 0; }

} // namespace infrastructure::lifecycle
