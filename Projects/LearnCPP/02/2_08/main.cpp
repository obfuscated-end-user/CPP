// https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files

#include <iostream>

// the example on the site looks like that it doesn't need this line below for it to compile
// i'm using vs code, maybe that's why
#include "add.cpp" // THIS WORKS

// int add(int x, int y); // needed so main.cpp knows that add() is a function defined elsewhere

int main() {
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // compile error
    return 0;
}