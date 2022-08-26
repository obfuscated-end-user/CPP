// https://www.learncpp.com/cpp-tutorial/arrays-part-ii/

#include <iostream>

int main() {
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << sizeof(array) << '\n'; // will print the size of the array multiplied by the size of an int
    std::cout << sizeof(int) << '\n';

    return 0;
}