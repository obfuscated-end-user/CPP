// https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors

#include <iostream>
#include <vector>

int main() {
	std::vector primes { 2, 3, 5, 7, 11 };	// hold the first 5 prime numbers (as int)

	std::cout << "The first prime number is : " << primes[0] << '\n';
	std::cout << "The first second number is : " << primes[1] << '\n';
	std::cout << "The sum of the first 5 primes is : " << primes[0] + primes[1] + primes[2] + primes[3] + primes[4] << '\n';

	std::cout << primes[5] << '\n';

	return 0;
};