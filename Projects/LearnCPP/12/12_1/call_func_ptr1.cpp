// https://www.learncpp.com/cpp-tutorial/function-pointers/

#include <iostream>

int foo(int x) {
    return x;
}

// explicit dereference
int main() {
    int (*fcnPtr)(int){ &foo }; // Initialize fcnPtr with function foo
    std::cout << (*fcnPtr)(5); // call function foo(5) through fcnPtr.

    return 0;
}

// (fcnPtr)(5) somehow works