// https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2

#include <iostream>
#include <string>
#include <string_view>

std::string_view firstAlphabetical(std::string_view s1, std::string_view s2) {
    return s1 < s2 ? s1 : s2;
}

int main() {
    std::string a { "World" };
    std::string b { "Hello" };

    std::cout << firstAlphabetical(a, b) << '\n';   // prints "Hello"

    return 0;
}