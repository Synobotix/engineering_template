add_subdirectory(core)
add_subdirectory(hal)
add_subdirectory(domain)

# BuildInfo — must be defined before application so AppRunner can link it
find_package(Git QUIET)
if(Git_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
endif()
if(NOT GIT_HASH)
    set(GIT_HASH "unknown")
endif()

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/BuildInfo.cpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/BuildInfo.cpp
    @ONLY
)

add_library(buildinfo ${CMAKE_CURRENT_BINARY_DIR}/BuildInfo.cpp)
target_include_directories(buildinfo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(buildinfo PUBLIC core)

add_subdirectory(application)
add_subdirectory(infrastructure)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE infrastructure)
