// https://www.learncpp.com/cpp-tutorial/multidimensional-arrays

#include <iostream>

int main() {
    constexpr int numRows{ 10 };
    constexpr int numCols{ 10 };

    // Declare a 10x10 array
    int product[numRows][numCols]{};

    // Calculate a multiplication table
    // starts at 1 because 0 * 0 is a waste of space
    for (int row{ 1 }; row < numRows; ++row) {
        for (int col{ 1 }; col < numCols; ++col) {
            product[row][col] = row * col;
        }
    }

    // Print the table
    for (int row{ 1 }; row < numRows; ++row) {
        for (int col{ 1 }; col < numCols; ++col) {
            std::cout << product[row][col] << '\t';
        }
        std::cout << '\n';
    }

    return 0;
}