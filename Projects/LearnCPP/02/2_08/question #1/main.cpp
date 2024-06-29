// https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files

#include <iostream>
#include "input.cpp"

int main() {
    int x = getInteger();
    int y = getInteger();
    
    std::cout << x << " + " << y << " is " << x + y << '\n';
    return 0;
}