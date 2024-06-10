// https://www.learncpp.com/cpp-tutorial/intro-to-loops-and-while-statements

/*
Write a program that prints out the letters a through z along with their ASCII codes.
*/

/*
// solution:
char myChar{ 'a' };
    while (myChar <= 'z')
    {
        std::cout << myChar << ' ' << static_cast<int>(myChar) << '\n';
        ++myChar;
    }
*/

#include <iostream>

int main() {
    int uppercase = 65;
    int lowercase = 97;

    std::cout << "Uppercase" << '\n';
    while (uppercase <= 90) {
        std::cout << static_cast<char>(uppercase) << '\t' << uppercase << '\n';
        ++uppercase;
    }
    std::cout << "Lowercase" << '\n';
    while (lowercase <= 122) {
        std::cout << static_cast<char>(lowercase) << '\t' << lowercase << '\n';
        ++lowercase;
    }

    /* char myChar{ 'a' };
    while (myChar <= 'z') {
        std::cout << myChar << ' ' << static_cast<int>(myChar) << '\n';
        ++myChar;
    } */
    return 0;
}