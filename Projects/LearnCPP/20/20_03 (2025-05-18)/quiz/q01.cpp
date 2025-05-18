// https://www.learncpp.com/cpp-tutorial/recursion

/*
A factorial of an integer N (written N!) is defined as the product (multiplication) of all the numbers between 1 and N (0! = 1). Write a recursive function called factorial that returns the factorial of the input. Test it with the first 7 factorials.
Hint: Remember that (x * y) = (y * x), so the product of all the numbers between 1 and N is the same as the product of all the numbers between N and 1.
*/

#include <iostream>

int factorial(int n) {
    if (n <= 0)
        return 1;
    
    return factorial(n - 1) * n;
}

int main() {
    for (int count { 0 }; count < 7; ++count)
        std::cout << factorial(count) << '\n';

    return 0;
}