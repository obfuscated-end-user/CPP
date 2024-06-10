// https://www.learncpp.com/cpp-tutorial/chapter-1-summary-and-quiz

#include <iostream>

int main()
{
    int num1, num2;
    std::cout << "Enter an integer: ";
    std::cin >> num1;
    std::cout << "Enter another integer: ";
    std::cin >> num2;
    std::cout << num1 << " + " << num2 << " is " << num1 + num2 << ".\n";
    std::cout << num1 << " - " << num2 << " is " << num1 - num2 << ".";
    return 0;
}