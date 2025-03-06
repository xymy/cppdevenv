#include <atomic>
#include <cstddef>
#include <memory>
#include <memory_resource>

#include <fmt/color.h>
#include <fmt/core.h>

constexpr auto rule_style =
    fmt::emphasis::bold | fmt::fg(fmt::terminal_color::green);

#define PRINT_RULE(TITLE)                                                      \
  do {                                                                         \
    fmt::print("{:-^60}\n", fmt::styled(" " TITLE " ", rule_style));           \
  } while (0)

constexpr auto func_style =
    fmt::emphasis::bold | fmt::fg(fmt::terminal_color::blue);
constexpr auto expr_style =
    fmt::emphasis::bold | fmt::fg(fmt::terminal_color::magenta);
constexpr auto value_style =
    fmt::emphasis::bold | fmt::fg(fmt::terminal_color::cyan);

#define PRINT_SIZEOF(EXPR)                                                     \
  do {                                                                         \
    fmt::print("{}({}) = {}\n", fmt::styled("sizeof", func_style),             \
               fmt::styled(#EXPR, expr_style),                                 \
               fmt::styled(sizeof(EXPR), value_style));                        \
  } while (0)

void sizeof_integral() {
  PRINT_SIZEOF(bool);
  PRINT_SIZEOF(char);
  PRINT_SIZEOF(wchar_t);
#ifdef __cpp_char8_t
  PRINT_SIZEOF(char8_t);
#endif
  PRINT_SIZEOF(char16_t);
  PRINT_SIZEOF(char32_t);
  PRINT_SIZEOF(signed char);
  PRINT_SIZEOF(unsigned char);
  PRINT_SIZEOF(short);
  PRINT_SIZEOF(unsigned short);
  PRINT_SIZEOF(int);
  PRINT_SIZEOF(unsigned int);
  PRINT_SIZEOF(long);
  PRINT_SIZEOF(unsigned long);
  PRINT_SIZEOF(long long);
  PRINT_SIZEOF(unsigned long long);
}

void sizeof_floating_point() {
  PRINT_SIZEOF(float);
  PRINT_SIZEOF(double);
  PRINT_SIZEOF(long double);
}

void sizeof_stddef() {
  PRINT_SIZEOF(std::size_t);
  PRINT_SIZEOF(std::ptrdiff_t);
  PRINT_SIZEOF(std::nullptr_t);
  PRINT_SIZEOF(std::max_align_t);
  PRINT_SIZEOF(std::byte);
}

void sizeof_memory() {
  PRINT_SIZEOF(std::unique_ptr<int>);
  PRINT_SIZEOF(std::shared_ptr<int>);
  PRINT_SIZEOF(std::weak_ptr<int>);
  PRINT_SIZEOF(std::atomic<std::shared_ptr<int>>);
  PRINT_SIZEOF(std::atomic<std::weak_ptr<int>>);
  PRINT_SIZEOF(std::enable_shared_from_this<int>);
  PRINT_SIZEOF(std::allocator<std::byte>);
  PRINT_SIZEOF(std::pmr::polymorphic_allocator<std::byte>);
}

int main() {
  PRINT_RULE("sizeof_integral");
  sizeof_integral();
  PRINT_RULE("sizeof_floating_point");
  sizeof_floating_point();
  PRINT_RULE("sizeof_stddef");
  sizeof_stddef();
  PRINT_RULE("sizeof_memory");
  sizeof_memory();
  return 0;
}
