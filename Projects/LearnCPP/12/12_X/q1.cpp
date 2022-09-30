// https://www.learncpp.com/cpp-tutorial/chapter-12-comprehensive-quiz/

/*
Question #1

Write function prototypes for the following cases. Use const if/when necessary.

a) A function named max() that takes two doubles and returns the larger of the two.

Show Solution

b) A function named swap() that swaps two integers.

Show Solution

c) A function named getLargestElement() that takes a dynamically allocated array of integers and returns the largest number in such a way that the caller can change the value of the element returned (don’t forget the length parameter).
*/

#include <iostream>

// a) A function named max() that takes two doubles and returns the larger of the two.
double max(double a, double b);

// b) A function named swap() that swaps two integers.
void swap(int& a, int& b);

// c) A function named getLargestElement() that takes a dynamically allocated array of integers and returns the largest number in such a way that the caller can change the value of the element returned (don’t forget the length parameter).
int& getLargestElement(int* array, int length); // YOU'RE A FUCKING RETARD

int main() {
    std::cout << '\n';
    return 0;
}