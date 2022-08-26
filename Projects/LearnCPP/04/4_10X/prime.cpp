// https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/

#include <iostream>

bool isPrime(int x) {
    return (x == 2 || x == 3 || x == 5 || x == 7); // if user entered 2 or 3 or 5 or 7 the digit is prime
}

// your dumbass made an odd even type thing. fucking retard.
int main() {
    int x {};
    std::cout << "Enter a number (0-9): ";
    std::cin >> x;

    if (isPrime(x))
        std::cout << "The digit is prime " << '\n';
    else
        std::cout << "The digit is not prime " << '\n';
    return 0;
}