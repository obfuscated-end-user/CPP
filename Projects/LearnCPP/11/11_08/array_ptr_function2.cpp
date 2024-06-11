// https://www.learncpp.com/cpp-tutorial/pointers-and-arrays

#include <iostream>

// C++ will implicitly convert parameter array[] to *array
void printSize(int array[]) {
    // array is treated as a pointer here, not a fixed array
    std::cout << sizeof(array) << '\n'; // prints the size of a pointer, not the size of the array!
}

int main() {
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << sizeof(array) << '\n'; // will print sizeof(int) * array length

    printSize(array); // the array argument decays into a pointer here

    return 0;
}

/*
these are identical:
    void printSize(int array[]);
    void printSize(int* array); - recommended by the tutorial
*/