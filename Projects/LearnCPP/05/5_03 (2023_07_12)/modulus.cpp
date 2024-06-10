// https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation
// yeah this is new from the site
// don't change the name of the folders

#include <iostream>

int main() {
    std::cout << "Enter an integer: ";
    int x;
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y;
    std::cin >> y;

    std::cout << "The remainder is: " << x % y << '\n';

    if ((x % y) == 0)
        std::cout << x << " is evenly divisible by " << y << '\n';
    else
        std::cout << x << " not is evenly divisible by " << y << '\n';

    return 0;
}