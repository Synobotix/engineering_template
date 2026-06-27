#include "infrastructure/watchdog/PosixWatchdog.hpp"

#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/watchdog.h>

namespace infrastructure::watchdog {

PosixWatchdog::PosixWatchdog(const char* device) noexcept
    : device_(device)
{}

PosixWatchdog::~PosixWatchdog()
{
    stop();
}

bool PosixWatchdog::start(uint32_t timeout_ms) noexcept
{
    fd_ = ::open(device_, O_RDWR);
    if (fd_ < 0) return false;

    int timeout_s = static_cast<int>((timeout_ms + 999u) / 1000u);
    ::ioctl(fd_, WDIOC_SETTIMEOUT, &timeout_s);
    return true;
}

void PosixWatchdog::kick() noexcept
{
    if (fd_ >= 0) ::write(fd_, "1", 1);
}

void PosixWatchdog::stop() noexcept
{
    if (fd_ >= 0) {
        ::write(fd_, "V", 1); // magic close — disarms the watchdog
        ::close(fd_);
        fd_ = -1;
    }
}

} // namespace infrastructure::watchdog
