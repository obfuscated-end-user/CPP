// https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing

#include <array>
#include <iostream>

int main() {
    std::array arr { 9, 7, 5, 3, 1 };           // note: not constexpr for this example
    constexpr int length { std::size(arr) };    // ok: return value is constexpr std::size_t and can be converted to int, not a narrowing conversion

    std::cout << "length: " << length <<'\n';

    return 0;
}