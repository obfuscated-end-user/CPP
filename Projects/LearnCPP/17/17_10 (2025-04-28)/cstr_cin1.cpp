// https://www.learncpp.com/cpp-tutorial/c-style-strings

#include <iostream>

int main() {
    char rolls[255] {}; // declare array large enough to hold 254 characters + null terminator
    std::cout << "Enter your rolls: ";
    std::cin >> rolls;
    std::cout << "You entered: " << rolls << '\n';

    return 0;
}