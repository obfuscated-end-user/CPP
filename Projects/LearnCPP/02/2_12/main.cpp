// https://www.learncpp.com/cpp-tutorial/header-guards

#include "square.h"
#include "geometry.h"
#include <iostream>

int main() {
    std::cout << "it fucking works" << '\n';
    std::cout << getSquareSides();
    return 0;
}

/*
Header guards:

#ifndef SOME_UNIQUE_NAME_HERE   = "if the name SOME_UNIQUE_NAME_HERE is not yet defined,"
#define SOME_UNIQUE_NAME_HERE   = "define SOME_UNIQUE_NAME_HERE here."

// your declarations (and certain types of definitions) here

#endif                          = "scope ends here, or ignore everything before this if ifndef is not satisfied"

*/