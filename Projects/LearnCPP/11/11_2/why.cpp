// https://www.learncpp.com/cpp-tutorial/arrays-part-ii/

#include <iostream>
#include <iterator>

void printSize(int array[]) {
    std::cout << std::size(array) << '\n'; // Error
}

int main() {
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << std::size(array) << '\n'; // will print the size of the array
    printSize(array);

    return 0;
}