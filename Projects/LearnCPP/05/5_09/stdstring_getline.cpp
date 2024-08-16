// https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring

#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your full name: ";
    std::string name {};

    // std::ws tells std::cin to ignore any leading whitespace before extraction
    std::getline(std::cin >> std::ws, name);        // read a full line of text into name

    std::cout << "Enter your favorite color: ";
    std::string color {};
    std::getline(std::cin >> std::ws, color);       // read a full line of text into color

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';
    return 0;
}