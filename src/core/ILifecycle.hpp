#pragma once

namespace core {

class ILifecycle {
public:
    virtual ~ILifecycle() = default;

    virtual bool start()              noexcept = 0;
    virtual void stop()               noexcept = 0;
    virtual bool is_running() const   noexcept = 0;
};

} // namespace core
