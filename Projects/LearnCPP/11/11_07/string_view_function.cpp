// https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2

#include <iostream>
#include <string>
#include <string_view>

// no longer using const reference
void printSV(std::string_view sv) {
    std::cout << sv << '\n';
}

int main() {
    std::string s{ "Hello, world" };
    std::string_view sv { s };

    printSV(s);              // ok: pass std::string
    printSV(sv);             // ok: pass std::string_view
    printSV("Hello, world"); // ok: pass C-style string literal

    return 0;
}

/*
There is one case where making the parameter a const std::string& is generally better: if your function needs to call some other function that takes a C-style string or std::string parameter, then const std::string& may be a better choice, as std::string_view is not guaranteed to be null-terminated (something that C-style string functions expect) and does not efficiently convert back to a std::string.
*/