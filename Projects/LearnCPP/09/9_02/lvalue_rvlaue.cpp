// https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues

#include <iostream>

int return5() {
    return 5;
}

int main() {
    int x{ 5 }; // 5 is an rvalue expression
    const double d{ 1.2 }; // 1.2 is an rvalue expression

    std::cout << x << '\n'; // x is a modifiable lvalue expression
    std::cout << d << '\n'; // d is a non-modifiable lvalue expression
    std::cout << return5(); // return5() is an rvalue expression (since the result is returned by value)
    std::cout << x + 1 << '\n'; // x + 1 is a rvalue
    std::cout << static_cast<int>(d) << '\n'; // the result of static casting d to an int is an rvalue

    return 0;
}