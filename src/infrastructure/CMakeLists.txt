add_library(infrastructure
    logging/ConsoleLogger.cpp
    config/EnvConfig.cpp
    lifecycle/SignalLifecycle.cpp
    timer/ChronoTimer.cpp
    concurrency/StdTask.cpp
    watchdog/PosixWatchdog.cpp
)
target_include_directories(infrastructure PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(infrastructure PUBLIC application hal)
