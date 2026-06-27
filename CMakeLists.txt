cmake_minimum_required(VERSION 3.20)
project(engineering_template CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(ENABLE_TESTS    "Build unit and E2E tests" OFF)
option(ENABLE_COVERAGE "Instrument with gcov for coverage reports" OFF)

add_library(project_warnings INTERFACE)
target_compile_options(project_warnings INTERFACE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall;-Wextra;-Wpedantic;-Werror>
    $<$<CXX_COMPILER_ID:MSVC>:/W4;/WX>
)

if(ENABLE_COVERAGE)
    if(NOT CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        message(FATAL_ERROR "Coverage requires GCC or Clang")
    endif()
    add_compile_options(--coverage -fprofile-arcs -ftest-coverage -O0 -g)
    add_link_options(--coverage)
endif()

add_subdirectory(src)

# enable_testing() is unconditional so `make test` (ctest) is always in the
# generated Makefile, regardless of ENABLE_TESTS.
enable_testing()

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()

# ------------------------------------------------------------------
# coverage — rebuild with gcov + run ctest + generate lcov HTML
# Requires: cmake -DENABLE_TESTS=ON -DENABLE_COVERAGE=ON
# ------------------------------------------------------------------
find_program(LCOV    lcov)
find_program(GENHTML genhtml)
if(LCOV AND GENHTML)
    add_custom_target(coverage
        COMMENT "Coverage report -> ${CMAKE_BINARY_DIR}/coverage-report/index.html"
        COMMAND ${LCOV}    --directory ${CMAKE_BINARY_DIR} --zerocounters
        COMMAND ${CMAKE_CTEST_COMMAND} --test-dir ${CMAKE_BINARY_DIR}
                           -j --output-on-failure
        COMMAND ${LCOV}    --directory ${CMAKE_BINARY_DIR} --capture
                           --output-file coverage.info
        COMMAND ${LCOV}    --remove coverage.info
                           '*/tests/*' '/usr/*' '*/googletest/*'
                           --output-file coverage.info
        COMMAND ${GENHTML} coverage.info
                           --output-directory ${CMAKE_BINARY_DIR}/coverage-report
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
else()
    add_custom_target(coverage
        COMMAND ${CMAKE_COMMAND} -E echo
                "lcov/genhtml not found — install with: apt install lcov"
    )
endif()

# ------------------------------------------------------------------
# mutate — dextool mutation testing
# Install: https://github.com/joakim-brannstrom/dextool
# ------------------------------------------------------------------
find_program(DEXTOOL dextool)
if(DEXTOOL)
    add_custom_target(mutate
        COMMENT "Mutation tests (dextool mutate)"
        COMMAND ${DEXTOOL} mutate run
                --config ${CMAKE_SOURCE_DIR}/dextool-mutate.toml
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
else()
    add_custom_target(mutate
        COMMAND ${CMAKE_COMMAND} -E echo
                "dextool not found — see https://github.com/joakim-brannstrom/dextool"
    )
endif()
