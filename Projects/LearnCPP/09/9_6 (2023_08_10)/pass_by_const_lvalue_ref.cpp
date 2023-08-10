// https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference

#include <iostream>

void printValue(const int& y) { // y is a const reference
    std::cout << y << '\n';
//  ++y; // not allowed: ref is const
}

int main() {
    int x = 5;
    printValue(x); // ok: x is a modifiable lvalue

    const int z = 5;
    printValue(z); // ok: z is a non-modifiable lvalue

    printValue(5); // ok: 5 is a literal rvalue

    return 0;
}