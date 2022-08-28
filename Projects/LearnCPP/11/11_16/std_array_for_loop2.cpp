// https://www.learncpp.com/cpp-tutorial/an-introduction-to-stdarray/

#include <array>
#include <cstddef> // std::size_t
#include <iostream>

int main() {
    std::array myArray { 7, 3, 1, 9, 5 };

    for (std::size_t i{ 0 }; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';

    std::cout << '\n';

    return 0;
}