// https://www.learncpp.com/cpp-tutorial/introduction-to-pointers

#include <iostream>

int main() {
    int value{ 45 };
    int* ptr{ &value }; // declare a pointer and initialize with address of value
    *ptr = &value; // assign address of value to ptr

    std::cout << '\n';
    return 0;
}

/*
third line, assigning a dereference with a reference
*/