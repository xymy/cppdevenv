cmake_minimum_required(VERSION 3.24)

project(
  cppdevenv
  VERSION      0.0
  DESCRIPTION  "Template project for C++"
  HOMEPAGE_URL https://github.com/xymy/cppdevenv
  LANGUAGES    CXX
)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not allowed.")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG        e69e5f977d458f2650bb346dadf2ad30c5320281 # 10.2.1
)
FetchContent_MakeAvailable(fmt)

add_executable(sizeof "src/sizeof.cpp")

target_link_libraries(sizeof fmt::fmt)
