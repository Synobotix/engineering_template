add_executable(test_core
    ResultTest.cpp
    RingBufferTest.cpp
    StateMachineTest.cpp
    EventBusTest.cpp
    RateLimiterTest.cpp
    LogStreamTest.cpp
)

target_include_directories(test_core PRIVATE
    ${CMAKE_SOURCE_DIR}/tests
)

target_link_libraries(test_core PRIVATE
    core
    test_options
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_core)
