// https://www.learncpp.com/cpp-tutorial/the-conditional-operator

#include <iostream>
#include <string>

int main() {
    constexpr bool inBigClassroom { false };
    constexpr int classSize { inBigClassroom ? 30 : 20 };
    std::cout << "The class size is: " << classSize << '\n';

    int x { 2 };
    int y { 1 };
    // not 10 - (x > y ? x : y) = 8
    // but (10 - x) > y ? x : y = 2
    int z { 10 - x > y ? x : y };
    std::cout << z << '\n';

    std::cout << (true ? 1 : 2) << '\n';    // okay: both operands have matching type int
    std::cout << (false ? 1 : 2.2) << '\n'; // okay: int value converted to double
    std::cout << (true ? -1 : 2u) << '\n';  // surprising result: -1 converted to unsigned int, result out of range

    constexpr int x1 { 5 };
    // std::cout << ((x1 != 5) ? x1 : "x1 is 5"); // compile error: compiler can't find common type for constexpr int and C-style string literal

    int x2 { 5 };   // intentionally non-constexpr for this example

    // we can explicitly convert the types to match
    std::cout << ((x2 != 5) ? std::to_string(x2) : std::string{"x2 is 5"}) << '\n';

    // or use an if-else statement
    if (x2 != 5)
        std::cout << x2 << '\n';
    else
        std::cout << "x2 is 5" << '\n';


    return 0;
}