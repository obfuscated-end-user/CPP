// https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring

#include <iostream>
#include <string>

int main() {
    std::string name { "Mark" };

    // std::string::length() returns an unsigned integral value, you may want to static_cast it before using it on i don't know, something involving maths
    int length { static_cast<int>(name.length()) };
    std::cout << name << " has " << length << " characters\n";

    // std::cout << std::ssize(name) << '\n';

    return 0;
}