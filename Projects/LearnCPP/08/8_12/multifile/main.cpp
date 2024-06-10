// https://www.learncpp.com/cpp-tutorial/default-arguments

#include "foo.h"
#include <iostream>

void print(int x, int y) {
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

// We’re able to use the default argument for function print() because main.cpp #includes foo.h,
// which has the forward declaration that defines the default argument.
// If the function has a forward declaration (especially one in a header file),
// put the default argument there. Otherwise, put the default argument in the function definition.
int main() {
    print(5);
    return 0;
}

