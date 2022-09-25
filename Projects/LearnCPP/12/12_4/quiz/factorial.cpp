// https://www.learncpp.com/cpp-tutorial/recursion/

/*
1. A factorial of an integer N (written N!) is defined as the product (multiplication) of all the numbers between 1 and N (0! = 1). Write a recursive function called factorial that returns the factorial of the input. Test it with the first 7 factorials.

Hint: Remember that (x * y) = (y * x), so the product of all the numbers between 1 and N is the same as the product of all the numbers between N and 1.
*/

#include <iostream>

int factorial(int n) {
    if (n <= 0)
        return 1;
    // std::cout << "n: " << n << '\n';
    return factorial(n - 1) * n;    // (n - 1) * n
}

int main() {
    // fucks up if you put a value larger than 12
    for (int i = 0; i <= 7; ++i)
        std::cout << factorial(i) << ' ';
    return 0;
}