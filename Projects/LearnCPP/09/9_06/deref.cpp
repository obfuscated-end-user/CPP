// https://www.learncpp.com/cpp-tutorial/introduction-to-pointers

#include <iostream>

int main() {
    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x

    std::cout << *(&x) << '\n'; // print the value at the memory address of variable x (parentheses not required, but make it easier to read)

    return 0;
}

/*
& - gets the memory address (not the value stored there)
* - gets the value stored at that memory address
*/