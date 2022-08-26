// https://www.learncpp.com/cpp-tutorial/break-and-continue/

#include <iostream>

int breakOrReturn() {
    // difference between break and return when used on loops
    while (true) { // infinite loop
        std::cout << "Enter 'b' to break or 'r' to return: ";
        char ch;
        std::cin >> ch;
        if (ch == 'b')
            break; // execution will continue at the first statement beyond the loop
        if (ch == 'r')
            return 1; // return will cause the function to immediately return to the caller (in this case, main())
    }
    // breaking the loop causes execution to resume here
    std::cout << "We broke out of the loop\n";
    return 0;
}

int main() {
    // examples of using break
    int sum{ 0 };
    // Allow the user to enter up to 10 numbers
    for (int count{ 0 }; count < 10; ++count) {
        std::cout << "Enter a number to add, or 0 to exit: ";
        int num{};
        std::cin >> num;
        // exit loop if user enters 0
        if (num == 0)
            break; // exit the loop now
        // otherwise add number to our sum
        sum += num;
    }
    // execution will continue here after the break
    std::cout << "The sum of all the numbers you entered is: " << sum << '\n';

    while (true) { // infinite loop
        std::cout << "Enter 0 to exit or any other integer to continue: ";
        int num{};
        std::cin >> num;
        // exit loop if user enters 0
        if (num == 0)
            break;
    }
    std::cout << "We're out!\n";

    // continue
    for (int count{ 0 }; count < 10; ++count) {
        // if the number is divisible by 4, skip this iteration
        if ((count % 4) == 0)
            continue; // go to next iteration
        // If the number is not divisible by 4, keep going
        std::cout << count << '\n';
        // The continue statement jumps to here
    }

    // unintended infinite while loop using continue
    int count{ 0 };
    while (count < 10) {
        if (count == 5)
            continue; // jump to end of loop body
        std::cout << count << '\n';
        ++count; // this statement is never executed after count reaches 5
        // The continue statement jumps to here
    }
    // since count will never be incremented by 1,
    // it will always stay at five.
    // therefore, infinite loop.
    // poetick reatard ca'nt speal

    /* int returnValue{ breakOrReturn() };
    std::cout << "Function breakOrReturn returned " << returnValue << '\n'; */
    return 0;
}