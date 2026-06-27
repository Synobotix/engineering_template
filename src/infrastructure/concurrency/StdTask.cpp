#include "infrastructure/concurrency/StdTask.hpp"

namespace infrastructure::concurrency {

StdTask::~StdTask()
{
    stop();
}

bool StdTask::start(core::ITaskBody& body) noexcept
{
    if (running_.load()) return false;
    running_.store(true);
    thread_ = std::thread([this, &body]() noexcept {
        body.run();
        running_.store(false);
    });
    return true;
}

void StdTask::stop() noexcept
{
    running_.store(false);
    if (thread_.joinable()) thread_.join();
}

bool StdTask::is_running() const noexcept
{
    return running_.load();
}

} // namespace infrastructure::concurrency
