// https://www.learncpp.com/cpp-tutorial/multidimensional-arrays/

#include <iostream>

int main() {
    int array[3][5] {
        { 1, 2, 3, 4, 5 }, // row 0
        { 6, 7, 8, 9, 10 }, // row 1
        { 11, 12, 13, 14, 15 } // row 2
    };

    for (int row{ 0 }; row < 3; ++row) { // step through the rows in the array
        for (int col{ 0 }; col < 5; ++col) { // step through each element in the row
            std::cout << array[row][col] << ' ';
        }
    }
}