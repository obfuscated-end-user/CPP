// https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/

#include <iostream>

int main() {
    /* char x {}; // assume this is assigned memory address 140
    char& ref { x }; // ref is an lvalue reference to x (when used with a type, & means lvalue reference) */

    // The address-of operator (&) returns the memory address of its operand.
    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x

    return 0;
}