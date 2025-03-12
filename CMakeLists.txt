cmake_minimum_required(VERSION 3.24)

project(
  cppdevenv
  VERSION      1.0
  DESCRIPTION  "Template project for C++"
  HOMEPAGE_URL https://github.com/xymy/cppdevenv
  LANGUAGES    CXX
)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not allowed.")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG        123913715afeb8a437e6388b4473fcc4753e1c9a # 11.1.4
)
FetchContent_MakeAvailable(fmt)

add_subdirectory("src")
