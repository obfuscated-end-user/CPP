// https://www.learncpp.com/cpp-tutorial/common-if-statement-problems

#include <iostream>

int main() {
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    if (x >= 0) // outer if statement
        // it is bad coding style to nest if statements this way
        if (x <= 20) // inner if statement
            std::cout << x << " is between 0 and 20\n";

    // which if statement does this else belong to?
    else    // dangling else problem
        std::cout << x << " is negative\n";

    return 0;
}