// https://www.learncpp.com/cpp-tutorial/constexpr-and-consteval-functions

#include <iostream>

// constexpr here
constexpr double calcCircumference(double radius) {
    constexpr double pi { 3.14159265359 };
    return 2.0 * pi * radius;
}

int main() {
    constexpr double circumference { calcCircumference(3.0) };  // compile error

    std::cout << "Our circle has circumference " << circumference << '\n';

    int x {};
    std::cin >> x;
    return 0;
}