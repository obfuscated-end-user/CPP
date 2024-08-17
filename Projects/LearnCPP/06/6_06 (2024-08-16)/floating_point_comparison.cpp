// https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons

#include <iostream>

int main() {
    // should equal 0.01 mathematically
    constexpr double d1 { 100.0 - 99.99 };
    constexpr double d2 { 10.0 - 9.99 };

    if (d1 == d2)
        std::cout << "d1 == d2" << '\n';
    else if (d1 > d2)
        std::cout << "d1 > d2" << '\n';
    else
        std::cout << "d1 < d2" << '\n';

    std::cout << "d1: " << d1 << '\n';
    std::cout << "d2: " << d2 << '\n';

    std::cout << std::boolalpha << (0.3 == 0.2 + 0.1);

    return 0;
}