// https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/

#include <iostream>
#include <string>

const int& getNextId() {
    static int s_x{ 0 };
    ++s_x;
    return s_x;
}

int main() {
    const int id1 { getNextId() }; // id1 is a normal variable now and receives a copy of the value returned by reference from getNextId()
    const int id2 { getNextId() }; // id2 is a normal variable now and receives a copy of the value returned by reference from getNextId()

    std::cout << id1 << id2;

    return 0;
}

// If a function returns a reference, and that reference is used to initialize or assign to a
// non-reference variable, the return value will be copied (as if it had been returned by value).