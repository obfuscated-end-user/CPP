// https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference

#include <iostream>
#include <string>

// THIS IS WHAT YOU SHOULD BE DOING WHEN WRITING FUNCTIONS
void printValue(const int& y) { // y is now a const reference
    std::cout << y << '\n';
}

int main() {
    int x { 5 };
    printValue(x); // ok: x is a modifiable lvalue

    const int z { 5 };
    printValue(z); // ok: z is a non-modifiable lvalue

    printValue(5); // ok: 5 is a literal rvalue

    return 0;
}