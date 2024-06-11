// https://www.learncpp.com/cpp-tutorial/pointers-and-arrays

#include <iostream>

int main() {
    int array[5]{ 9, 7, 5, 3, 1 };

    std::cout << sizeof(array) << '\n'; // will print sizeof(int) * array length

    int* ptr{ array };
    std::cout << sizeof(ptr) << '\n'; // will print the size of a pointer

    return 0;
}