// https://www.learncpp.com/cpp-tutorial/c-style-strings

/*
Write a function to print a C-style string character by character. Use a pointer and pointer arithmetic to step through each character of the string and print that character. Write a `main` function that tests the function with the string literal “Hello, world!”.
*/

#include <iostream>

// str will point to the first letter of the C-style string.
// Note that str points to a const char, so we can not change the values it points to.
// However, we can point str at something else. This doe snot change the value of the argument.

void printCString(const char str[]) {
    // While we haven't encountered a null terminator
    while (*str != '\0') {
        // print the current character
        std::cout << *str;
        // and use pointer arithmetic to move str to the next character
        ++str;
    }
}

int main() {
    printCString("Hello world!");
    std::cout << '\n';

    return 0;
}