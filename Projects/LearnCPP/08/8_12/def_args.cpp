// https://www.learncpp.com/cpp-tutorial/default-arguments

#include <iostream>

void print(int x, int y=4) { // 4 is the default argument
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

// Default arguments can only be supplied for the rightmost parameters. The following is not allowed:
// void print(int x=10, int y); // not allowed

int main() {
    print(1, 2); // y will use user-supplied argument 2
    print(3); // y will use default argument 4

}