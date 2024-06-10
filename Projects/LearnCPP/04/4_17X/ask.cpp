// https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring

#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your full name: ";
    std::string fullName;
    std::getline(std::cin >> std::ws, fullName);
    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;
    int fullNameLength = static_cast<int>(fullName.length());
    std::cout << "Your age + length of name is: " << fullNameLength + age;
    return 0;
}