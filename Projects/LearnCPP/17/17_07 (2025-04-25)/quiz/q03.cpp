// https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays

/*
A “perfect square” is a natural number whose square root is an integer. We can make perfect squares by multiplying a natural number (including zero) by itself. The first 4 perfect squares are: 0, 1, 4, 9.
Use a global constexpr C-style array to hold the perfect squares between 0 and 9 (inclusive). Repeatedly ask the user to enter a single digit integer, or -1 to quit. Print whether the digit the user entered is a perfect square.
The output should match the following:

```
Enter a single digit integer, or -1 to quit: 4
4 is a perfect square
Enter a single digit integer, or -1 to quit: 5
5 is not a perfect square
Enter a single digit integer, or -1 to quit: -1
Bye
```

Hints: Use a range-based for loop to traverse the C-style array to look for a match.
*/

#include <iostream>

namespace ProgramData {
    constexpr int squares[] { 0, 1, 4, 9 };
}

bool matchSquare(int input) {
    for (const auto& e : ProgramData::squares) {
        if (input == e)
            return true;
    }

    return false;
}

int main() {
    while (true) {
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        int input {};
        std::cin >> input;

        if (input == -1)
            break;

        if (matchSquare(input))
            std::cout << input << " is a perfect square\n";
        else
            std::cout << input << " is not a perfect square\n";
    }

    std::cout << "Bye\n";

    return 0;
}