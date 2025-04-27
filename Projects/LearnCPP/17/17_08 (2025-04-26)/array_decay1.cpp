// https://www.learncpp.com/cpp-tutorial/c-style-array-decay

#include <iostream>

int main() {
    int arr[5] { 9, 7, 5, 3, 1 };   // our array has elements of type int
    
    // First, let's prove that arr decays into an int* pointer
    auto ptr { arr };   // evaluation causes arr to decay, type deduction should deduce type int*
    std::cout << std::boolalpha << (typeid(ptr) == typeid(int*)) << '\n';   // Prints true if the type of ptr is int*

    // Now let's prove that the pointer holds the address of the first element of the array
    std::cout << std::boolalpha << (&arr[0] == ptr) << '\n';

    return 0;
}