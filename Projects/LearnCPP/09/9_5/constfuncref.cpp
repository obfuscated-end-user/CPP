// https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/

#include <iostream>
#include <string>

void printValue(int& y) { // y only accepts modifiable lvalues
    std::cout << y << '\n';
}

int main() {
    int x { 5 };
    printValue(x); // ok: x is a modifiable lvalue

    const int z { 5 };
    printValue(z); // error: z is a non-modifiable lvalue

    printValue(5); // error: 5 is an rvalue

    return 0;
}