// https://www.learncpp.com/cpp-tutorial/for-statements

/*
Write a for loop that prints every even number from 0 to 20.
*/

#include <iostream>

int main() {
    for (int i = 0; i <= 20; i+=2)
        std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}