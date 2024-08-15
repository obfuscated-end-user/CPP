// https://www.learncpp.com/cpp-tutorial/comma-and-conditional-operators
// Moved to "6.5 — The comma operator"
// 2024/08/13 - https://www.learncpp.com/cpp-tutorial/the-comma-operator

#include <iostream>

int main() {
    int x{ 1 };
    int y{ 2 };

    std::cout << (++x, ++y) << '\n'; // increment x and y, evaluates to the right operand

    // conditional operator
    // (boolean expression) ? if true : else/if false
    int z = (5 > 4) ? 4 : 3;
    std::cout << z;
    return 0;
}