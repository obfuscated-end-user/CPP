// https://www.learncpp.com/cpp-tutorial/forward-declarations

#include <iostream>

// int add(int x, int y); // forward declaration of add() (using a function prototype)

// you can do this, but it's considered bad practice by the c++ neckbeard overlords
int add(int, int); // valid function prototype

int main() {
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
    return 0;
}

// remove this and you'll get a linking error (not a compile error)
int add(int x, int y) { // even though the body of add() isn't defined until here
    return x + y;
}