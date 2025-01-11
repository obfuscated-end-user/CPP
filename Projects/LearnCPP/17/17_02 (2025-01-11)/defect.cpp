// https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing

#include <array>
#include <iostream>

void printLength(const std::array<int, 5> &arr) {
    constexpr int length { std::size(arr) };    // compile error!
    std::cout << "length " << length << '\n';
}

int main() {
    std::array arr { 9, 7, 5, 3, 1 };
    constexpr int length { std::size(arr) };    // works just fine
    std::cout << "length " << length << '\n';

    return 0;
}