// https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/

#include <iostream>

int main() {
    // Once we have a pointer holding the address of another object,
    // we can then use the dereference operator (*) to access the value at that address.
    int x{ 5 };
    std::cout << x << '\n'; // print the value of variable x
    int* ptr{ &x }; // ptr holds the address of x
    std::cout << *ptr << '\n'; // use dereference operator to print the value at the address that ptr is holding (which is x's address)

    return 0;
}
/*
std::cout << *ptr << '\n';  // prints the value stored at the memory address this pointer points
std::cout << ptr << '\n';   // prints the pointer itself
*/
