// https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray

#include <array>
#include <iostream>

int main() {
    constexpr std::array<int, 5> prime { 2, 3, 5, 7, 11 };

    std::cout << prime[3];  // print the value of element with index 3 (7)
    std::cout << prime[9];  // invalid index (undefined behavior)

    return 0;
}