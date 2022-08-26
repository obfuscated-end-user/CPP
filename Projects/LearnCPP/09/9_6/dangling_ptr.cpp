// https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/

#include <iostream>

int main() {
    int x{ 5 };
    int* ptr{ &x };
    std::cout << *ptr; // valid

    {
        int y{ 6 };
        ptr = &y;
        std::cout << *ptr; // valid
    } // y goes out of scope, and ptr is now dangling

    std::cout << *ptr; // undefined behavior from dereferencing a dangling pointer

    return 0;
}