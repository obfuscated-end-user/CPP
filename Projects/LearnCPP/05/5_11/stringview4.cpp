// https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2

#include <iostream>
#include <string>
#include <string_view>

std::string getName() {
    std::string s { "Mark" };
    return s;
}

int main() {
    std::string_view name1 { getName() };    // name1 initialized with return value of function
    std::cout << name1 << '\n';              // undefined behavior

    // less-obvious version
    using namespace std::string_literals;
    std::string_view name2 { "Mark"s };
    std::cout << name2 << '\n';

    return 0;
}