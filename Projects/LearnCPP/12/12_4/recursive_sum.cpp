// https://www.learncpp.com/cpp-tutorial/recursion/

#include <iostream>

// returns the sum of all the integers between 1 (inclusive) and sumto (inclusive)
// returns 0 for negative numbers

int sumTo(int sumto) {
    if (sumto <= 0)
        return 0;   // base case (termination condition) when user passed in an unexpected argument (0 or negative)
    if (sumto == 1)
        return 1; // normal base case (termination condition)

    return sumTo(sumto - 1) + sumto; // recursive function call
}

int main() {
    std::cout << sumTo(5) << '\n';  // thought this will do anything
}