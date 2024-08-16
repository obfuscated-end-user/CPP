// https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2

#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::string s { "Hello, world!" };
    std::string_view sv { s };  // sv is now viewing s

    s = "Hello universe!";  // modifies s, which invalidates sv (s is still valid)
    std::cout << sv << '\n';    // undefined behavior

    sv = s;
    std::cout << sv << '\n';    // prints "Hello, universe!"

    return 0;
}