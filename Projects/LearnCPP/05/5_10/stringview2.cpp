// https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view

#include <iostream>
#include <string>
#include <string_view>

int main() {
    using namespace std::string_literals;      // access the s suffix
    using namespace std::string_view_literals; // access the sv suffix

    std::string name { "Mark" };
    std::string_view sv { name };   // sv is now viewing name
    std::cout << sv << '\n';        // prints Mark

    sv = "John";                    // sv is now viewing "John" (does not change name)
    std::cout << sv << '\n';        // prints John

    std::cout << name << '\n';      // prints Mark

    std::cout << "moo\n"sv; // sv suffix is a std::string_view literal

    // std::string_view can be constexpr, unlike std::string
    constexpr std::string_view s { "Hello, world!" };
    std::cout << s << '\n';

    return 0;
}