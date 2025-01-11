// https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing

#include <array>
#include <iostream>

int main() {
    constexpr std::array prime { 2, 3, 5, 7, 11 };
    
    std::cout << std::get<3>(prime);    // print the value of element with index 3
    std::cout << std::get<9>(prime);    // invalid index (compile error)

    return 0;
}