// https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/

#include <iostream>

int main()
{
    int mainNumber = main() + main(); // doesn't work
    std::cout << mainNumber;
    return 0;
}