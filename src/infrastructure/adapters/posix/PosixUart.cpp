#include "infrastructure/adapters/posix/PosixUart.hpp"

#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <cstring>

namespace infrastructure::adapters::posix {

PosixUart::PosixUart(std::string_view device_path) noexcept
{
    std::size_t len = (device_path.size() < sizeof(device_path_) - 1)
                    ? device_path.size()
                    : sizeof(device_path_) - 1;
    std::memcpy(device_path_, device_path.data(), len);
    device_path_[len] = '\0';
}

PosixUart::~PosixUart()
{
    if (fd_ >= 0) ::close(fd_);
}

static speed_t to_speed(hal::UartBaudRate baud) noexcept
{
    switch (baud) {
        case hal::UartBaudRate::k9600:   return B9600;
        case hal::UartBaudRate::k19200:  return B19200;
        case hal::UartBaudRate::k38400:  return B38400;
        case hal::UartBaudRate::k115200: return B115200;
    }
    return B115200;
}

core::Status PosixUart::configure(const hal::UartConfig& config) noexcept
{
    fd_ = ::open(device_path_, O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (fd_ < 0) return core::status::err(core::errors::invalid);

    termios tty{};
    if (::tcgetattr(fd_, &tty) != 0) return core::status::err(core::errors::unknown);

    speed_t speed = to_speed(config.baud_rate);
    ::cfsetispeed(&tty, speed);
    ::cfsetospeed(&tty, speed);

    tty.c_cflag  = (tty.c_cflag & ~CSIZE) | CS8;
    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~(PARENB | CSTOPB);
    tty.c_iflag  = IGNPAR;
    tty.c_oflag  = 0;
    tty.c_lflag  = 0;

    if (::tcsetattr(fd_, TCSANOW, &tty) != 0) return core::status::err(core::errors::unknown);
    return core::status::ok();
}

core::Status PosixUart::write(const uint8_t* data, std::size_t length) noexcept
{
    if (fd_ < 0) return core::status::err(core::errors::invalid);
    ssize_t written = ::write(fd_, data, length);
    if (written < 0 || static_cast<std::size_t>(written) != length)
        return core::status::err(core::errors::unknown);
    return core::status::ok();
}

core::Result<std::size_t, core::Error> PosixUart::read(uint8_t* buffer, std::size_t max_length) noexcept
{
    using R = core::Result<std::size_t, core::Error>;
    if (fd_ < 0) return R::err(core::errors::invalid);
    ssize_t n = ::read(fd_, buffer, max_length);
    if (n < 0) return R::err(core::errors::unknown);
    return R::ok(static_cast<std::size_t>(n));
}

bool PosixUart::is_data_available() const noexcept
{
    if (fd_ < 0) return false;
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(fd_, &fds);
    timeval tv{0, 0};
    return ::select(fd_ + 1, &fds, nullptr, nullptr, &tv) > 0;
}

} // namespace infrastructure::adapters::posix
