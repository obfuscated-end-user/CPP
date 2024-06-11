// https://www.learncpp.com/cpp-tutorial/pointers-and-arrays

#include <iostream>

int main() {
    int array[5]{ 9, 7, 5, 3, 1 };

    // Deferencing an array returns the first element (element 0)
    std::cout << *array << '\n'; // will print 9!

    char name[]{ "Jason" }; // C-style string (also an array)
    std::cout << *name << '\n'; // will print 'J'

    return 0;
}