// https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes

#include <iostream>

int main() {
    enum class Color { // "enum class" defines this as a scoped enum rather than an unscoped enum
        red, // red is considered part of Color's scope region
        blue,
    };

    std::cout << red;        // compile error: red not defined in this scope region
    std::cout << Color::red; // compile error: std::cout doesn't know how to print this (will not implicitly convert to int)

    Color color { Color::blue }; // okay

    return 0;
}