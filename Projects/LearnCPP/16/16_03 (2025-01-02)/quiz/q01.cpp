// https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem

/*
Question #1

Initialize a std::vector with the following values: ‘h’, ‘e’, ‘l’, ‘l’, ‘o’. Then print the length of the array (use std::size()). Finally, print the value of the element with index 1 using the subscript operator and the at() member function.

The program should output the following:

The array has 5 elements.
ee
*/

#include <iostream>
#include <vector>

int main() {
    std::vector arr { 'h', 'e', 'l', 'l', 'o' };
    std::cout << "The array has " << std::size(arr) << " elements.\n";
    std::cout << arr[1] << arr.at(1) <<'\n';

    return 0;
}