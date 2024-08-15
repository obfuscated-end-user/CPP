// https://www.learncpp.com/cpp-tutorial/constexpr-and-consteval-functions

#include <iostream>

int getValue(int x) {
    return x;
}

// This function can be evaluated at runtime
// When evaluated at compile-time, te function will produce a compilation error
// because the call to getValue(x) cannot be resolved at compile-time

constexpr int foo(int x) {
    return getValue(x);
}

int main() {
    int x { foo(5) }; // okay: will evaluate at runtime
    constexpr int y { foo(5) }; // compile error: foo(5) can't evaluate at compile time

    return 0;
}