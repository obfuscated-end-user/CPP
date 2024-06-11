// https://www.learncpp.com/cpp-tutorial/an-introduction-to-stdvector

#include <iostream>
#include <vector>

int main() {
    // no need to specify length at the declaration
    std::vector<int> array;
    std::vector<int> array2 = { 9, 7, 5, 3, 1 }; // use initializer list to initialize array (before C++11)
    std::vector<int> array3 { 9, 7, 5, 3, 1 }; // use uniform initialization to initialize array

    // as with std::array, the type can be omitted since C++17
    std::vector array4 { 9, 7, 5, 3, 1 }; // deduced to std::vector<int>

    std::cout << array4.at(10);
    return 0;
}