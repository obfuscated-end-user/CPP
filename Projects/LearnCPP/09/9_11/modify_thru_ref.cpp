// https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address

#include <iostream>

// takes two integers by non-const reference, and returns the greater by reference
int& max(int& x, int& y) {
    return (x > y) ? x : y;
}

int main() {
    int x { 5 };
    int y { 6 };

    max(x, y) = 7; // sets the greater of x or y to 7
    std::cout << x << y;

    return 0;
}