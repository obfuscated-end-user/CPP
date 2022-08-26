// https://www.learncpp.com/cpp-tutorial/5-3-modulus-and-exponentiation/

/*
Write a program that asks the user to input an integer, and tells the user whether the number is even or odd. Write a function called isEven() that returns true if an integer passed to it is even, and false otherwise. Use the modulus operator to test whether the integer parameter is even.

Hint: You’ll need to use if statements and the comparison operator (==) for this program. See lesson 4.9 -- Boolean values if you need a refresher on how to do this.

Your program should match the following output:

Enter an integer: 5
5 is odd

*/

#include <iostream>

int getInteger() {
    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;
    return x;
}

bool isEven(int number) {
    return (number % 2) == 0;
}

int main() {
    int integer = getInteger();
    if (isEven(integer))
        std::cout << integer << " is even\n";
    else
        std::cout << integer << " is odd\n";
    return 0;
}