// https://www.learncpp.com/cpp-tutorial/constexpr-variables

#include <iostream>

int five() {
    return 5;
}

int main() {
    // constexpr is conster than const

    // these are constant expressions
    constexpr double gravity { 9.8 };
    constexpr int sum { 4 + 5 };
    constexpr int something { sum };

    std::cout << "Enter your age: ";
    int age {};
    std::cin >> age;

    // these are not
    // should not compile
    constexpr int myAge { age };
    constexpr int f { five() };

    return 0;
}