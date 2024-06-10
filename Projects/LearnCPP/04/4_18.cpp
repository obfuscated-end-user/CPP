// https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view

#include <iostream>
#include <string>
#include <string_view>

void printSV(std::string_view str) {
    std::cout << str << '\n';
}

// Returning a std::string_view from a function is usually a bad idea.
std::string_view returnStdStringView(std::string_view str) {
    return str;
}

int main() {
    std::string_view s{ "Hello, world!" }; // now a std::string_view
    printSV(s);
    constexpr std::string_view sample { "Hello, world!" }; // can also be used with constexpr
    std::cout << returnStdStringView("foo");
    return 0;
}