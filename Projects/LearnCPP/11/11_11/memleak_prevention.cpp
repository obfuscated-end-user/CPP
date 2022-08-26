// https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/

#include <iostream>

int main() {
    int value{ 5 };
    int* ptr{ new int{} }; // allocate memory
    delete ptr; // return memory back to operating system
    ptr = &value; // reassign pointer to address of value

    return 0;
}

// yes, delete doesn't mean delete. it just means that to tell the program to stop using that space in memory and return it to the operating system.