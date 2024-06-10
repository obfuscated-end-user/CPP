// https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping

/*
Write a function called calculate() that takes two integers and a char representing one of the following mathematical operations: +, -, *, /, or % (modulus). Use a switch statement to perform the appropriate mathematical operation on the integers, and return the result. If an invalid operator is passed into the function, the function should print an error. For the division operator, do an integer division.

Hint: “operator” is a keyword, variables can’t be named “operator”.
*/

#include <iostream>

int calculate(int x, int y, char op) {
    int result;
    switch (op) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':{
            if ((x || y) <= 0)
                result = 0;
            else
                result = x / y;
            break;
        }
        case '%':
            result = x % y;
            break;
        default:
            result = 0;
            break;
    }
    return result;
}

/*
// solution on site
int calculate(int x, int y, char op)
{
    switch (op)
    {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '%':
            return x % y;
        default:
            std::cerr << "calculate(): Unhandled case\n";
            return 0;
    }
}*/

int main() {
    std::cout << calculate(0, 0 , '/');
    return 0;
}