include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
    GIT_SHALLOW    TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST           OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Relax -Wpedantic for test targets only — GTest macros use gnu extensions
add_library(test_options INTERFACE)
target_compile_options(test_options INTERFACE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wno-pedantic>
)

add_subdirectory(unit)
add_subdirectory(e2e)
