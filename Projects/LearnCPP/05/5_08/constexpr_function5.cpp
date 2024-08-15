// https://www.learncpp.com/cpp-tutorial/constexpr-and-consteval-functions

#include <iostream>

consteval int goo(int c) {  // c is not constexpr, and cannot be used in constant expressions
    return c;
}

constexpr int foo(int b) {  // b is not constexpr, and cannot be used in constant expressions
    constexpr int b2 { b }; // compile error: constexpr variable requires constant expression initializer
    return goo(b);  // compile error:  consteval function call requires constant expression argument
}

int main() {
    constexpr int a { 5 };
    std::cout << foo(a);

    return 0;
}