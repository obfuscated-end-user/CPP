// https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-array-indexing/

#include <iostream>

int main() {
    int array[]{ 9, 7, 5, 3, 1 };

     std::cout << &array[1] << '\n'; // print memory address of array element 1
     std::cout << array+1 << '\n'; // print memory address of array pointer + 1

     std::cout << array[1] << '\n'; // prints 7
     std::cout << *(array+1) << '\n'; // prints 7 (note the parenthesis required here)

    return 0;
}

// array[n] is the same as *(array + n), where n is an integer