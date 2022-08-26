// https://www.learncpp.com/cpp-tutorial/comma-and-conditional-operators/

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