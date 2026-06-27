#include "infrastructure/adapters/posix/PosixGpio.hpp"

#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>

namespace infrastructure::adapters::posix {

PosixGpio::PosixGpio(uint32_t gpio_number) noexcept
    : gpio_number_(gpio_number)
{}

PosixGpio::~PosixGpio()
{
    if (value_fd_ >= 0) ::close(value_fd_);
}

core::Status PosixGpio::configure(hal::GpioDirection direction) noexcept
{
    char buf[16];
    int  len;

    int export_fd = ::open("/sys/class/gpio/export", O_WRONLY);
    if (export_fd < 0) return core::status::err(core::errors::invalid);
    len = std::snprintf(buf, sizeof(buf), "%u", gpio_number_);
    ::write(export_fd, buf, static_cast<std::size_t>(len));
    ::close(export_fd);

    char path[64];
    std::snprintf(path, sizeof(path), "/sys/class/gpio/gpio%u/direction", gpio_number_);
    int dir_fd = ::open(path, O_WRONLY);
    if (dir_fd < 0) return core::status::err(core::errors::invalid);
    const char* dir_str = (direction == hal::GpioDirection::Output) ? "out" : "in";
    ::write(dir_fd, dir_str, std::strlen(dir_str));
    ::close(dir_fd);

    std::snprintf(path, sizeof(path), "/sys/class/gpio/gpio%u/value", gpio_number_);
    int flags = (direction == hal::GpioDirection::Output) ? O_WRONLY : O_RDONLY;
    value_fd_ = ::open(path, flags);
    if (value_fd_ < 0) return core::status::err(core::errors::invalid);

    return core::status::ok();
}

core::Result<hal::GpioState, core::Error> PosixGpio::read() const noexcept
{
    using R = core::Result<hal::GpioState, core::Error>;
    if (value_fd_ < 0) return R::err(core::errors::invalid);

    char val;
    ::lseek(value_fd_, 0, SEEK_SET);
    if (::read(value_fd_, &val, 1) != 1) return R::err(core::errors::unknown);
    return R::ok(val == '1' ? hal::GpioState::High : hal::GpioState::Low);
}

core::Status PosixGpio::write(hal::GpioState state) noexcept
{
    if (value_fd_ < 0) return core::status::err(core::errors::invalid);
    char val = (state == hal::GpioState::High) ? '1' : '0';
    if (::write(value_fd_, &val, 1) != 1) return core::status::err(core::errors::unknown);
    return core::status::ok();
}

core::Status PosixGpio::toggle() noexcept
{
    auto state = read();
    if (state.is_err()) return core::status::err(state.error());
    return write(state.value() == hal::GpioState::High ? hal::GpioState::Low : hal::GpioState::High);
}

} // namespace infrastructure::adapters::posix
