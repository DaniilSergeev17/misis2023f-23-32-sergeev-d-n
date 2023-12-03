add_library(rational rational.hpp rational.cpp)
add_executable(test_rational test_rational.cpp)
target_link_libraries(test_rational PRIVATE rational)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_rational)
