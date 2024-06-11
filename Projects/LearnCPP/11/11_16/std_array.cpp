// https://www.learncpp.com/cpp-tutorial/an-introduction-to-stdarray

#include <iostream>
#include <array>

int main() {
    std::array<int, 3> myArray1; // declare an integer array with length 3
    std::array<int, 5> myArray2 = { 9, 7, 5, 3, 1 }; // initializer list
    std::array<int, 5> myArray3 { 9, 7, 5, 3, 1 }; // list initialization

    // Unlike built-in fixed arrays, with std::array you can not omit the array length when providing an initializer:
    // std::array<int, > myArray { 9, 7, 5, 3, 1 }; // illegal, array length must be provided
    // std::array<int> myArray { 9, 7, 5, 3, 1 }; // illegal, array length must be provided

    // However, since C++17, it is allowed to omit the type and size. They can only be omitted together, but not one or the other, and only if the array is explicitly initialized.
    // prefer doing this
    std::array myArray4 { 9, 7, 5, 3, 1 }; // The type is deduced to std::array<int, 5>
    std::array myArray5 { 9.7, 7.31 }; // The type is deduced to std::array<double, 2>

    // Since C++20, it is possible to specify the element type but omit the array length. This makes creation of std::array a little more like creation of C-style arrays. To create an array with a specific type and deduced size, we use the std::to_array function:
    // auto myArray1 { std::to_array<int, 5>({ 9, 7, 5, 3, 1 }) }; // Specify type and size
    // auto myArray2 { std::to_array<int>({ 9, 7, 5, 3, 1 }) }; // Specify type only, deduce size
    // auto myArray3 { std::to_array({ 9, 7, 5, 3, 1 }) }; // Deduce type and size
    // also, don't do this ^^^

    //  You can also assign values to the array using an initializer list
    std::array<int, 5> myArray6;
    myArray6 = { 0, 1, 2, 3, 4 }; // okay
    myArray6 = { 9, 8, 7 }; // okay, elements 3 and 4 are set to zero!
    // myArray6 = { 0, 1, 2, 3, 4, 5 }; // not allowed, too many elements in initializer list!

    // Just like built-in fixed arrays, the subscript operator does not do any bounds-checking. If an invalid index is provided, bad things will probably happen.
    // std::array supports a second form of array element access (the at() function) that does bounds checking:
    std::array myArray7 { 9, 7, 5, 3, 1 };
    myArray7.at(1) = 6; // array element 1 is valid, sets array element 1 to value 6
    // myArray7.at(9) = 10; // array element 9 is invalid, will throw a runtime error
    std::cout << myArray7.at(1);
    return 0;
}