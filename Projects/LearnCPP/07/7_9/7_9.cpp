// https://www.learncpp.com/cpp-tutorial/for-statements/

#include <iostream>
// returns the value base ^ exponent -- watch out for overflow!
int pow(int base, int exponent) {
    int total{ 1 };
    for (int count{ 0 }; count < exponent; ++count)
        total *= base;
    return total;
}

int main() {
    for (int count{ 1 }; count <= 10; ++count)
        std::cout << count << ' ';
    std::cout << '\n';

    // does the same thing as above but looks more retarded
    { // the block here ensures block scope for count
        int count{ 1 }; // our init-statement
        while (count <= 10) { // our condition 
            std::cout << count << ' '; // our statement
            ++count; // our end-expression
        }
    }

    std::cout << '\n';
    std::cout << pow(4, 4) << '\n';

    std::cout << '\n';
    int count{ 0 };
    for ( ; count < 10; ) { // no init-statement or end-expression
        std::cout << count << ' ';
        ++count;
    }
    /*
    // infinite for loop
    for (;;)
        statement;
    */

    // for loop with two variables
    std::cout << '\n';
    for (int x{ 0 }, y{ 9 }; x < 10; ++x, --y)
        std::cout << x << ' ' << y << '\n';

    // nested for loops
    std::cout << '\n';
    for (char c{ 'a' }; c <= 'e'; ++c) { // outer loop on letters
		std::cout << c; // print our letter first
		for (int i{ 0 }; i < 3; ++i) // inner loop on all numbers
			std::cout << i;
		std::cout << '\n';
	}
    return 0;
}