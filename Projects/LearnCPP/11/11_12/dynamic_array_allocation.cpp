// https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays

#include <iostream>

int main() {
    std::cout << "Enter a positive integer: ";
    int length{};
    std::cin >> length;

    int* array{ new int[length]{} }; // use array new.  Note that length does not need to be constant!

    std::cout << "I just allocated an array of integers of length " << length << '\n';

    array[0] = 5; // set element 0 to value 5

    delete[] array; // use array delete to deallocate array

    // we don't need to set array to nullptr/0 here because it's going to go out of scope immediately after this anyway

    return 0;
}