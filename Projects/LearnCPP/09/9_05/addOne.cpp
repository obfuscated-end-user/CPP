// https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference

#include <iostream>

void addOne(int& y) { // y is bound to the actual object x
    ++y; // this modifies the actual object x
}

/* void addOne(int y) { // y is a copy of x
    ++y; // this modifies the copy of x, not the actual object x
} */

int main() {
    int x { 5 };
    std::cout << "value = " << x << '\n';
    addOne(x);
    std::cout << "value = " << x << '\n'; // x has not been modified

    return 0;
}