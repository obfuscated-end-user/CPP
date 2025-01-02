// https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem

#include <iostream>
#include <vector>

int main() {
    std::vector prime { 2, 3, 5, 7, 11 };
    std::cout << "length (size()): " << prime.size() << '\n';   // returns length as type `size_type` (alias for `std::size_t`)
    std::cout << "length (std::size()): " << std::size(prime) << '\n';  // C++17, returns length as type `size_type` (alias for `std::size_t`)

    int length1 { static_cast<int>(prime.size()) };  // static_cast return value to int

    std::cout << "length (std::ssize()): " << std::ssize(prime) << '\n';    // C++20, returns length as a large signed integral type

    int length2 { static_cast<int>(std::ssize(prime)) };
    auto length3 { std::ssize(prime) };

    return 0;
}