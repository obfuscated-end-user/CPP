// https://www.learncpp.com/cpp-tutorial/c-style-string-symbolic-constants

#include <iostream>

int main() {
    const char name [] { "Draymond" };      // case 1: const C-style string initialized with C-style string
    const char* const color { "Green" };    // case 2: const pointer to C-style string literal

    std::cout << name << ' ' << color << '\n';

    auto s1 { "Bert" };     // type deduced as const char*
    auto* s2 { "Bert" };    // type deduced as const char*
    auto& s3 { "Bert" };    // type deduced as const char(&)[5]

    return 0;
}