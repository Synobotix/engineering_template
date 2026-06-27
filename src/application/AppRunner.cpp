#include "application/AppRunner.hpp"

namespace application {

AppRunner::AppRunner(core::ILifecycle& lifecycle, core::ILogger& logger) noexcept
    : lifecycle_(lifecycle)
    , logger_(logger)
{}

int AppRunner::run()
{
    logger_.info() << core::BuildInfo::project_name
                   << " v" << core::BuildInfo::version
                   << " (" << core::BuildInfo::git_hash << ")"
                   << " built " << core::BuildInfo::build_date
                   << " " << core::BuildInfo::build_time;

    if (!lifecycle_.start()) {
        logger_.error() << "lifecycle start failed";
        return 1;
    }
    logger_.info() << "application started";

    // Replace with platform idle (RTOS task delay, epoll…) as needed.
    while (lifecycle_.is_running()) {}

    lifecycle_.stop();
    logger_.info() << "application stopped";
    return 0;
}

} // namespace application
