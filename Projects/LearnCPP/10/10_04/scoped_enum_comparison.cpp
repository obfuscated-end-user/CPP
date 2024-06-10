// https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes

#include <iostream>

int main() {
    enum class Color {
        red,
        blue,
    };

    Color shirt { Color::red };

    if (shirt == Color::red) // this Color to Color comparison is okay
        std::cout << "The shirt is red!\n";
    else if (shirt == Color::blue)
        std::cout << "The shirt is blue!\n";

    return 0;
}