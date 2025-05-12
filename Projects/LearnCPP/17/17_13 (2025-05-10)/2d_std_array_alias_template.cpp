// https://www.learncpp.com/cpp-tutorial/multidimensional-stdarray

#include <array>
#include <iostream>

// An alias template for a two-dimensional std::array
template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

// An alias template for a three-dimensional std::array
template <typename T, std::size_t Row, std::size_t Col, std::size_t Depth>
using Array3d = std::array<std::array<std::array<T, Depth>, Col>, Row>;

// When uing Array2d as a function parameter, we need to respecify the template parameters
template <typename T, std::size_t Row, std::size_t Col>
void printArray(const Array2d<T, Row, Col> &arr) {
    for (const auto& arow : arr) {  // get each array row
        for (const auto& e : arow)  // get each element of the row
            std::cout << e << ' ';
        std::cout << '\n';
    }
}

int main() {
    // Define a two-dimensional array of int with 3 rows and 4 columns
    Array2d<int, 3, 4> arr {{
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    }};

    printArray(arr);

    return 0;
}