// https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing

/*
Initialize a std::array with the following values: ‘h’, ‘e’, ‘l’, ‘l’, ‘o’. Print the length of the array, and then use operator[], at() and std::get() to print the value of the element with index 1.
The program should print:
The length is 5
eee
*/

#include <array>
#include <iostream>

int main() {
    constexpr std::array arr { 'h', 'e', 'l', 'l', 'o' };
    std::cout << "The length is " << std::size(arr) << '\n';
    std::cout << arr[1] << arr.at(1) << std::get<1>(arr) << '\n';

    return 0;
}