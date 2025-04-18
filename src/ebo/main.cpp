#include <fmt/base.h>
#include <fmt/color.h>

constexpr auto func_style =
    fmt::emphasis::bold | fmt::fg(fmt::terminal_color::blue);
constexpr auto expr_style =
    fmt::emphasis::bold | fmt::fg(fmt::terminal_color::magenta);
constexpr auto value_style =
    fmt::emphasis::bold | fmt::fg(fmt::terminal_color::cyan);

#define PRINT_SIZEOF(EXPR)                                         \
  do {                                                             \
    fmt::print("{}({}) = {}\n", fmt::styled("sizeof", func_style), \
               fmt::styled(#EXPR, expr_style),                     \
               fmt::styled(sizeof(EXPR), value_style));            \
  } while (0)

namespace ebo {

struct Base {};

struct Derived1 : Base {
  int i;
};

struct Derived2 : Base {
  Base b;
  int i;
};

struct Derived3 : Base {
  Derived1 d1;
  int i;
};

}  // namespace ebo

#ifdef _MSC_VER
#define NO_UNIQUE_ADDRESS [[msvc::no_unique_address]]
#else
#define NO_UNIQUE_ADDRESS [[no_unique_address]]
#endif

namespace nua {

struct Base {};

struct Derived1 {
  NO_UNIQUE_ADDRESS Base b;
  int i;
};

struct Derived2 {
  NO_UNIQUE_ADDRESS Base b1;
  NO_UNIQUE_ADDRESS Base b2;
  int i;
};

struct Derived3 {
  NO_UNIQUE_ADDRESS Base b;
  NO_UNIQUE_ADDRESS Derived1 d1;
  int i;
};

}  // namespace nua

int main() {
  {
    using namespace ebo;
    PRINT_SIZEOF(Base);
    PRINT_SIZEOF(Derived1);
    PRINT_SIZEOF(Derived2);
    PRINT_SIZEOF(Derived3);
  }
  {
    using namespace nua;
    PRINT_SIZEOF(Base);
    PRINT_SIZEOF(Derived1);
    PRINT_SIZEOF(Derived2);
    PRINT_SIZEOF(Derived3);
  }
  return 0;
}
