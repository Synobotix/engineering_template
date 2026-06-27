add_executable(test_infrastructure
    ConsoleLoggerTest.cpp
)

target_include_directories(test_infrastructure PRIVATE
    ${CMAKE_SOURCE_DIR}/tests
)

target_link_libraries(test_infrastructure PRIVATE
    infrastructure
    test_options
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_infrastructure)
