// https://www.learncpp.com/cpp-tutorial/for-each-loops

#include <iostream>
#include <vector>

int main() {
    std::vector fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };           // note use of std::vector here rather than a fixed array
    // std::vector<int> fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };   // Before C++17

    for (auto number : fibonacci) {
        std::cout << number << ' ';
    }

    std::cout << '\n';

    return 0;
}