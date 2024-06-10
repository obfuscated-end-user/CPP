// https://www.learncpp.com/cpp-tutorial/floating-point-and-integral-promotion

#include <iostream>

void printInt(int x) {
    std::cout << x;
}

// integral promotion
int main() {
    printInt(2);

    short s{ 3 }; // there is no short literal suffix, so we'll use a variable for this one
    printInt(s); // numeric promotion of short to int

    printInt('a'); // numeric promotion of char to int, prints 97
    printInt(true); // numeric promotion of bool to int, prints 1

    return 0;
}