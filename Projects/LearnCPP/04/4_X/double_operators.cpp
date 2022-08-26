// https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/

/*
    Write the following program: The user is asked to enter 2 floating point numbers (use doubles). The user is then asked to enter one of the following mathematical symbols: +, -, *, or /. The program computes the answer on the two numbers the user entered and prints the results. If the user enters an invalid symbol, the program should print nothing.

    Example:
    Enter a double value: 6.2
    Enter a double value: 5
    Enter one of the following: +, -, *, or /: *
    6.2 * 5 is 31
*/

#include <iostream>

int main() {
    /* double num1, num2;
    char symbol;
    std::cout << "Enter two floating point numbers (separated by space): ";
    std::cin >> num1;
    std::cin >> num2;

    std::cout << "Enter a valid mathematical symbol (+, -, *, or /): ";
    std::cin >> symbol;

    if (symbol == '+') {
        std::cout << num1 << " + " << num2 << " is " << num1 + num2 << '\n';
    } else if (symbol == '-') {
        std::cout << num1 << " - " << num2 << " is " << num1 - num2 << '\n';
    } else if (symbol == '*') {
        std::cout << num1 << " * " << num2 << " is " << num1 * num2 << '\n';
    } else if (symbol == '/') {
        if (num1 == 0 || num2 == 0) {
            std::cout << "can't divide by 0";
        } else {
            std::cout << num1 << " / " << num2 << " is " << num1 / num2 << '\n';
        }
    } */

    // slightly modified version
    // should've done this shit with functions fucking retard
    double num1, num2;
    char symbol;
    std::cout << "Enter a double value: ";
    std::cin >> num1;
    std::cout << "Enter a double value: ";
    std::cin >> num2;

    std::cout << "Enter one of the following: +, -, *, or /: ";
    std::cin >> symbol;

    if (symbol == '+') {
        std::cout << num1 << " + " << num2 << " is " << num1 + num2 << '\n';
    } else if (symbol == '-') {
        std::cout << num1 << " - " << num2 << " is " << num1 - num2 << '\n';
    } else if (symbol == '*') {
        std::cout << num1 << " * " << num2 << " is " << num1 * num2 << '\n';
    } else if (symbol == '/') {
        if (num1 == 0 || num2 == 0) {
            std::cout << "can't divide by 0";
        } else {
            std::cout << num1 << " / " << num2 << " is " << num1 / num2 << '\n';
        }
    }
}

// solution

/*
double getDouble()
{
    std::cout << "Enter a double value: ";
    double x{};
    std::cin >> x;
    return x;
}

char getOperator()
{
    std::cout << "Enter one of the following: +, -, *, or / ";
    char operation{};
    std::cin >> operation;
    return operation;
}

void printResult(double x, char operation, double y)
{
    if (operation == '+')
        std::cout << x << " + " << y << " is " << x + y << '\n';
    else if (operation == '-')
        std::cout << x << " - " << y << " is " << x - y << '\n';
    else if (operation == '*')
        std::cout << x << " * " << y << " is " << x * y << '\n';
    else if (operation == '/')
        std::cout << x << " / " << y << " is " << x / y << '\n';
}

int main()
{
    double x { getDouble() };
    double y { getDouble() };

    char operation { getOperator() };

    printResult(x, operation, y);

    return 0;
}
*/