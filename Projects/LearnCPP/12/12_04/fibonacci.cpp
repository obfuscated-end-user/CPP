// https://www.learncpp.com/cpp-tutorial/recursion/

#include <iostream>

int fibonacci(int count) {
    // std::cout << count << ' ';
    if (count == 0)
        return 0; // base case (termination condition)
    if (count == 1)
        return 1;
    return fibonacci(count - 1) + fibonacci(count - 2);
}

// And a main program to display the first 13 Fibonacci numbers
int main() {
    for (int count = 0; count < 13; ++count)
        std::cout << fibonacci(count) << ' ';

    return 0;
}

/*
Fibonacci numbers are defined mathematically as:
F(n) =	0 if n = 0
        1 if n = 1
        f(n-1) + f(n-2) if n > 1

tl;dr
F(n) is 0 if n is equal to 0
F(n) is 1 if n is equal to 1
else
F(n) is equal to f(n-1) (itself minus 1) + f(n-2) (itself minus 2), if n is greater than 1 (e.g. 2, 3, 4...)
ex.
let n = 2
f(2-1) + f(2-2)
1 + 0 = 1
let n = 3
f(3-1) + f(3-2)
2 + 1 = 3
let n = 4

in the example above, it printed:
0 1 1 2 3 5 8 13 21 34 55 89 144
corresponding numbers
1 2 3

wahtever

the above program also calls fibonacci() 1205 times, which is stupid
*/