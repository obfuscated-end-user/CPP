// https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting

#include <iostream>

int main() {
    int x {};
    const int* ptr { &x };  // assume 4 byte ints

    std::cout << ptr << '\n';

    ++ptr;  // ptr = ptr + 1
    std::cout << ptr << '\n';

    --ptr;  // ptr = ptr - 1
    std::cout << ptr << '\n';

    return 0;
}