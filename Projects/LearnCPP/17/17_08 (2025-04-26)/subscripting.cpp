// https://www.learncpp.com/cpp-tutorial/c-style-array-decay

#include <iostream>

int main() {
    const int arr1[] { 9, 7, 5, 3, 1 };
    std::cout << arr1[2] << '\n';   // subscript decayed array to get element 2, prints 5

    const int arr2[] { 9, 7, 5, 3, 1 };
    const int* ptr { arr2 };    // arr decays into a pointer
    std::cout << ptr[2];        // subscript ptr to get element 2, prints 5

    return 0;
}