// https://www.learncpp.com/cpp-tutorial/arrays-part-ii

#include <iostream>

int main() {
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << "The array has: " << sizeof(array) / sizeof(array[0]) << " elements\n";

    return 0;
}