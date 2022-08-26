// https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/

#include <iostream>

int main() {
    enum class Color {
        red,
        blue,
    };

    Color color { Color::blue };

    // LONG ASS ERROR MESSAGE
    std::cout << color; // won't work, because there's no implicit conversion to int
    std::cout << static_cast<int>(color); // will print 1

    return 0;
}