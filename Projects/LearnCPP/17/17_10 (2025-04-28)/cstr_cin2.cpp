// https://www.learncpp.com/cpp-tutorial/c-style-strings

#include <iostream>
#include <iterator> // for std::size

int main() {
    char rolls[255] {}; // declare array large enough to hold 254 characters + null terminator
    std::cout << "Enter your rolls: ";
    std::cin.getline(rolls, std::size(rolls));
    std::cout << "You entered: " << rolls << '\n';

    return 0;
}