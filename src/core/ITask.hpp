#pragma once

namespace core {

class ITaskBody {
public:
    virtual ~ITaskBody() = default;
    virtual void run() noexcept = 0;
};

class ITask {
public:
    virtual ~ITask() = default;

    [[nodiscard]] virtual bool start(ITaskBody& body) noexcept = 0;
    virtual void               stop()                 noexcept = 0;
    [[nodiscard]] virtual bool is_running()     const noexcept = 0;
};

} // namespace core
