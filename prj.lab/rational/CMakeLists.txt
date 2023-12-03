add_library(complex complex.cpp complex.hpp)
set_property(TARGET complex PROPERTY CXX_STANDARD 20)
target_include_directories(complex PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS complex)


add_library(rational rational.hpp rational.cpp)
add_executable(test_rational test_rational.cpp)
target_link_libraries(test_rational PRIVATE rational)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_rational)
