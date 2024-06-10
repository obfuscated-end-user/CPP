// https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity

#include <iostream>

int getValue() {
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

int main() {
    // bad practice
    // std::cout << getValue() + (getValue() * getValue()); // a + (b * c)
    int a{ getValue() }; // will execute first
    int b{ getValue() }; // will execute second
    int c{ getValue() }; // will execute third
    std::cout << a + (b * c);
    return 0;
}