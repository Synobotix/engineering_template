#pragma once

#include "core/ITask.hpp"
#include <atomic>
#include <thread>

namespace infrastructure::concurrency {

class StdTask final : public core::ITask {
public:
    ~StdTask() override;

    bool start(core::ITaskBody& body) noexcept override;
    void stop()                       noexcept override;
    bool is_running()           const noexcept override;

private:
    std::thread       thread_;
    std::atomic<bool> running_{false};
};

} // namespace infrastructure::concurrency
