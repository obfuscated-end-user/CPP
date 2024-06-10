// https://www.learncpp.com/cpp-tutorial/introduction-to-pointers

#include <iostream>

int main() {
    // When declaring a pointer type, place the asterisk next to the type name.
    int x { 5 };    // normal variable
    int& ref { x }; // a reference to an integer (bound to x)
    int* ptr;       // a pointer to an integer
    int *ptr2 = &x; // this also works but looks ehhh
    std::cout << ptr2 << '\n';

    return 0;
}