#include <iostream>

int main() {
    int number;
    std::cout << "enter a number: ";
    std::cin >> number;

    // find center
    if ((number % 2) == 0)
        std::cout << "Even, " << number / 2;
    else
        std::cout << "Odd, " << (number / 2) + 1;
}