// https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray

#include <array>

int main() {
    std::array<int, 7> a {};    // Using a literal constant

    constexpr int len { 8 };
    std::array<int, len> b {};  // Using a constexpr variable

    enum Colors {
        red,
        green,
        blue,
        max_colors
    };

    std::array<int, max_colors> c {};   // Using an enumerator

#define DAYS_PER_WEEK 7
    std::array<int, DAYS_PER_WEEK> d {};    // Using a macro (don't do this, use a constexpr variable instead)

    return 0;
}