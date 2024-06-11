// https://www.learncpp.com/cpp-tutorial/arrays-part-ii

#include <iostream>

void printSize(int array[]) {
    std::cout << sizeof(array) / sizeof(array[0]) << '\n';
                // 8           /            4
}

int main() {
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << sizeof(array) / sizeof(array[0]) << '\n';
    printSize(array);   // returns the size of int*, not the size of the array itself (2 in this case)

    return 0;
}