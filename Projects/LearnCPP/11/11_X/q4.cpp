// https://www.learncpp.com/cpp-tutorial/chapter-11-comprehensive-quiz

/*
Write a function to print a C-style string character by character. Use a pointer to step through each character of the string and print that character. Stop when you hit the null terminator. Write a main function that tests the function with the string literal “Hello, world!”.

Hint: Use the ++ operator to advance the pointer to the next character.

const char* str{ "Hello, world!" };
std::cout << *str; // H
++str;
std::cout << *str; // e
// ...
*/

#include <iostream>
#include <cstring>
#include <string.h>

void printCString(const char* cstring, int& size) {
    std::cout << "foo\n";
/*     for (int i; *cstring < size; ++cstring) {
        std::cout << *cstring;
    } */

    while(*cstring < size) {
        std::cout << *cstring;
        ++cstring;
    }

    /*
    // DON'T USE
    for (int i = 0; i < size; ++cstring) {
        *cstring + i;
        std::cout << *cstring;
    }
    */
    std::cout << "bar\n";
}

void printCString2(const char* cstring) {
    // THERE IS SOMETHING CALLED A WHILE LOOP, USE IT
    while (*cstring != '\0') {  // while character is not a null terminator
        std::cout << *cstring;  // print that character
        ++cstring;              // move to next character
    }
}

int main() {
    const char* str {"Hello World!"};
    int size = std::strlen(str);
    printCString2(str);
    /* std::cout << *str;
    ++str;
    std::cout << *str; */
    return 0;
}