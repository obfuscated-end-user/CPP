// https://www.learncpp.com/cpp-tutorial/arrays-part-ii

#include <iostream>
#include <iterator> // for std::size

int main() {
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << "The array has: " << std::size(array) << " elements\n";

    return 0;
}