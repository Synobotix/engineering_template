add_library(hal INTERFACE)
target_include_directories(hal INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(hal INTERFACE core)
