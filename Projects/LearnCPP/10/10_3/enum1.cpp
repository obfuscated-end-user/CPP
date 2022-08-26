// https://www.learncpp.com/cpp-tutorial/unscoped-enumeration-input-and-output/

#include <iostream>

enum Color {
    black,      // assigned 0
    red,        // assigned 1
    blue,       // assigned 2
    green,      // assigned 3
    white,      // assigned 4
    cyan,       // assigned 5
    yellow,     // assigned 6
    magenta,    // assigned 7
};

enum Animal {
    cat = -3,
    dog,            // assigned -2
    pig,            // assigned -1
    horse = 5,
    giraffe = 5,    // shares same value as horse
    chicken,        // assigned 6
    // assigning the same value to two enumerators in the same enumeration should generally be avoided
};

int main() {
    Color shirt{ blue }; // This actually stores the integral value 2

    return 0;
}