#include "application/AppRunner.hpp"
#include "infrastructure/config/EnvConfig.hpp"
#include "infrastructure/lifecycle/SignalLifecycle.hpp"
#include "infrastructure/logging/ConsoleLogger.hpp"

int main()
{
    infrastructure::logging::ConsoleLogger     logger;
    infrastructure::config::EnvConfig          config;
    infrastructure::lifecycle::SignalLifecycle lifecycle;

    application::AppRunner runner{lifecycle, logger};
    return runner.run();
}
