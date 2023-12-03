add_library(dynarr dynarr.hpp dynarr.cpp)

add_executable(test_dynarr test_dynarr.cpp)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_dynarr)