// https://www.learncpp.com/cpp-tutorial/the-stack-and-the-heap

#include <iostream>

void foo() {
    foo();  // recursive
    std::cout << "hi";
}

int main() {
    foo();

    return 0;
}