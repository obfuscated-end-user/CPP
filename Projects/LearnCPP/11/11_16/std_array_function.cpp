// https://www.learncpp.com/cpp-tutorial/an-introduction-to-stdarray

#include <array>
#include <iostream>

void printLength(const std::array<double, 5>& myArray) {
    std::cout << "length: " << myArray.size() << '\n';
}

int main() {
    std::array myArray { 9.0, 7.2, 5.4, 3.6, 1.8 };

    printLength(myArray);

    return 0;
}

// note:
// array is passed by const reference instead of just nothing