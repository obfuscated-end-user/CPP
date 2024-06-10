// https://www.learncpp.com/cpp-tutorial/for-statements

/*
What’s wrong with the following for loop?

// Print all numbers from 9 to 0
for (unsigned int count{ 9 }; count >= 0; --count)
    std::cout << count << ' ';
*/

#include <iostream>

int main() {
    // Print all numbers from 9 to 0
    // remove unsigned keyword
    for (int count{ 9 }; count >= 0; --count)
        std::cout << count << ' ';
    return 0;
}