// https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/

#include "io.h"
#include <iostream>

int readNumber() {
    std::cout << "Enter a number: ";
    int num;
    std::cin >> num;
    return num;
}

void writeAnswer(int answer) {
    std::cout << "The answer is " << answer << '\n';
}