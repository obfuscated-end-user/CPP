// https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input

#include <iostream>
#include <limits>

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble() {
    while (true) {// Loop until user enters a valid input
        std::cout << "Enter a double value: ";
        double x{};
        std::cin >> x;

        // Check for failed extraction
        if (!std::cin) { // has a previous extraction failed?
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // and remove the bad input
            std::cerr << "Oops, that input is invalid.  Please try again.\n";
        } else {
            ignoreLine(); // remove any extraneous input
            return x;
        }
    }
}

char getOperator() {
    while (true) { // Loop until user enters a valid input
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;
        ignoreLine(); // // remove any extraneous input

        // Check whether the user entered meaningful input
        switch (operation) {
            case '+':
            case '-':
            case '*':
            case '/':
                return operation; // return it to the caller
            default: // otherwise tell the user what went wrong
                std::cerr << "Oops, that input is invalid.  Please try again.\n";
        }
    } // and try again
}

void printResult(double x, char operation, double y) {
    switch (operation) {
        case '+':
            std::cout << x << " + " << y << " is " << x + y << '\n';
            break;
        case '-':
            std::cout << x << " - " << y << " is " << x - y << '\n';
            break;
        case '*':
            std::cout << x << " * " << y << " is " << x * y << '\n';
            break;
        case '/':
            std::cout << x << " / " << y << " is " << x / y << '\n';
            break;
        default: // Being robust means handling unexpected parameters as well, even though getOperator() guarantees operation is valid in this particular program
            std::cerr << "Something went wrong: printResult() got an invalid operator.\n";
    }
}

int main() {
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);

    return 0;
}

/*
As you write your programs, consider how users will misuse your program, especially around text input. For each point of text input, consider:
    Could extraction fail?
    Could the user enter more input than expected?
    Could the user enter meaningless input?
    Could the user overflow an input?

The following code will clear any extraneous input:
    #include <limits> // for std::numeric_limits
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

The following code will test for and fix failed extractions or overflow:
if (!std::cin) { // has a previous extraction failed or overflowed?
    // yep, so let's handle the failure
    std::cin.clear(); // put us back in 'normal' operation mode
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
}

w/o comments:
if (!std::cin) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
*/