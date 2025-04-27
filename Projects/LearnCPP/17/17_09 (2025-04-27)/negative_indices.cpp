// https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting

#include <iostream>

int main() {
    const int arr[] { 9, 8, 7, 6, 5 };
    
    // Set ptr to point at element 3
    const int* ptr { &arr[3] };

    // Prove that we're pointing at element 3
    std::cout << *ptr << ptr[0] << '\n';        // prints 66
    // Prove that ptr[-1] is element 2!
    std::cout << *(ptr - 1) << ptr[-1] << '\n'; // prints 77

    return 0;
}