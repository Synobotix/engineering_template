add_executable(test_e2e
    AppRunnerE2ETest.cpp
)

target_include_directories(test_e2e PRIVATE
    ${CMAKE_SOURCE_DIR}/tests
)

target_link_libraries(test_e2e PRIVATE
    application
    test_options
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_e2e)
