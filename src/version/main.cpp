#include <fmt/base.h>
#include <fmt/color.h>

#include "version.hpp"

constexpr auto name_style =
    fmt::emphasis::bold | fmt::fg(fmt::terminal_color::magenta);
constexpr auto value_style =
    fmt::emphasis::bold | fmt::fg(fmt::terminal_color::cyan);

#define PRINT_VALUE(VALUE)                                  \
  do {                                                      \
    fmt::print("{}: {}\n", fmt::styled(#VALUE, name_style), \
               fmt::styled(VALUE, value_style));            \
  } while (0)

int main() {
  PRINT_VALUE(CPPDEVENV_VERSION);
  PRINT_VALUE(CPPDEVENV_VERSION_MAJOR);
  PRINT_VALUE(CPPDEVENV_VERSION_MINOR);
  return 0;
}
