// https://www.learncpp.com/cpp-tutorial/null-pointers

#include <iostream>

int main() {
    int* ptr {}; // Create a null pointer
    std::cout << *ptr; // Dereference the null pointer

    return 0;
}