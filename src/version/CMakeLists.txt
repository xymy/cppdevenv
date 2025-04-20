configure_file(
  "version.hpp.in"
  "version.hpp"
  @ONLY
)

add_executable(version "main.cpp")
target_compile_features(version PRIVATE cxx_std_20)
target_include_directories(version PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
target_link_libraries(version PRIVATE fmt::fmt)
