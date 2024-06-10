// https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives

#include <iostream>
#include "foolib.h"

// function that you defined that apparently has the same name as from an another function
// from some random library
int someFcn(double) {
    return 1;
}

int main() {
    using namespace foo; // Because we're lazy and want to access foo:: qualified names without typing the foo:: prefix
    std::cout << someFcn(0); // The literal 0 should be 0.0, but this is an easy mistake to make
    // prints 2 for some reason
    return 0;
}