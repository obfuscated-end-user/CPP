// https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/

#include <iostream>

int main() {
    int value { 5 };

    int* ptr { &value };
    std::cout << *ptr << '\n'; // Indirection through pointer to int to get int value

    int** ptrptr { &ptr };
    std::cout << **ptrptr << '\n'; // first indirection to get pointer to int, second indirection to get int value

    return 0;
}