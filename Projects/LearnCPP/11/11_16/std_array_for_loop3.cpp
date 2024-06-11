// https://www.learncpp.com/cpp-tutorial/an-introduction-to-stdarray

#include <array>
#include <iostream>

int main() {
    std::array myArray { 7, 3, 1, 9, 5 };

    // Print the array in reverse order.
    for (auto i{ myArray.size() }; i-- > 0; )
        std::cout << myArray[i] << ' ';

    std::cout << '\n';

    return 0;
}