// https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/

#include <iostream>

int main() {
    int x{ 5 };

    int* ptr;        // an uninitialized pointer (holds a garbage address)
    int* ptr2{};     // a null pointer (we'll discuss these in the next lesson)
    int* ptr3{ &x }; // a pointer initialized with the address of variable x

    std::cout << ptr << '\n';
    std::cout << ptr2 << '\n';
    std::cout << ptr3 << '\n';

    return 0;
}