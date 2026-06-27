#pragma once

#include "core/BuildInfo.hpp"
#include "core/ILifecycle.hpp"
#include "core/ILogger.hpp"

namespace application {

class AppRunner {
public:
    AppRunner(core::ILifecycle& lifecycle, core::ILogger& logger) noexcept;

    int run();

private:
    core::ILifecycle& lifecycle_;
    core::ILogger&    logger_;
};

} // namespace application
