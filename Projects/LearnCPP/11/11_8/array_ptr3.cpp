// https://www.learncpp.com/cpp-tutorial/pointers-and-arrays/

#include <iostream>

int main() {
    int array[5]{ 9, 7, 5, 3, 1 };
    std::cout << *array << '\n'; // will print 9

    int* ptr{ array };
    std::cout << *ptr << '\n'; // will print 9

    return 0;
}