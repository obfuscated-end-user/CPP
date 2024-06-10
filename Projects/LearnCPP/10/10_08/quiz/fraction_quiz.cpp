// https://www.learncpp.com/cpp-tutorial/struct-passing-and-miscellany

/*
Create a struct to hold a fraction. The struct should have an integer numerator and an integer denominator member.

Write a function to read in a Fraction from the user, and use it to read-in two fraction objects. Write another function to multiply two Fractions together and return the result as a Fraction (you don’t need to reduce the fraction). Write another function that prints a fraction.

Your program’s output should match the following:

Enter a value for the numerator: 1
Enter a value for the denominator: 2

Enter a value for the numerator: 3
Enter a value for the denominator: 4

Your fractions multiplied together: 3/8
*/

#include <iostream>

struct Fraction {
    int numerator {};
    int denominator {1};
};

Fraction getFraction() {
    int numerator, denominator;

    std::cout << "Enter a value for the numerator: ";
    std::cin >> numerator;
    std::cout << "Enter a value for the denominator: ";
    std::cin >> denominator;

    return {numerator, denominator};    // you can return something like this as long it fits the struct
}

// remember, always use const type& unless you have a specific reason not to do so
Fraction multiplyFraction(const Fraction& fraction1, const Fraction& fraction2) {
    int numerator = fraction1.numerator * fraction2.numerator;
    int denominator = fraction1.denominator * fraction2.denominator;

    return {numerator, denominator};
}

void printFraction(const Fraction& fraction) {
    std::cout << fraction.numerator << '/' << fraction.denominator;
}

int main() {
    Fraction fraction1 {getFraction()};
    std::cout << '\n';
    Fraction fraction2 {getFraction()};

    std::cout << "\nYour fractions multiplied together: ";
    printFraction(multiplyFraction(fraction1, fraction2));

    return 0;
}