// https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz

/*
2a) Upgrade the following program using type aliases:

#include <iostream>

namespace constants
{
    inline constexpr double pi { 3.14159 };
}

double convertToRadians(double degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    double degrees{};
    std::cin >> degrees;

    double radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}

2b) Building on quiz 2a, explain why the following statement will or won’t compile:

radians = degrees;
*/

#include <iostream>

using doubleDegrees = double;
using doubleRadians = double;

namespace constants {
    inline constexpr double pi { 3.14159 };
}

double convertToRadians(doubleDegrees degrees) {
    return degrees * constants::pi / 180;
}

int main() {
    std::cout << "Enter a number of degrees: ";
    doubleDegrees degrees{};
    std::cin >> degrees;

    doubleRadians radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    radians = degrees;

    return 0;
}

/*
// should've done something like this:
using degrees_t = double;
using radians_t = double;
*/