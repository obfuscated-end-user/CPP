// https://www.learncpp.com/cpp-tutorial/function-template-instantiation/

#include "Max.h" // import template definition for max<T, T>()
#include <iostream>

void foo(); // forward declaration for function foo

int main() {
    std::cout << max(3, 5);
    foo();
    return 0;
}