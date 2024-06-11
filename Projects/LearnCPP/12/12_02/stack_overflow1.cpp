// https://www.learncpp.com/cpp-tutorial/the-stack-and-the-heap

#include <iostream>

int main() {
    int stack[10000000];
    std::cout << "hi" << stack[0]; // we'll use stack[0] here so the compiler won't optimize the array away

    return 0;
}

// doesn't print "hi" because the int array breaks the program before it can do anything