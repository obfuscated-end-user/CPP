// https://www.learncpp.com/cpp-tutorial/stdstring-length-and-capacity

#include <cstdlib>	// for rand() and srand()
#include <ctime>	// for time()
#include <iostream>
#include <string>

int main() {
	std::srand(std::time(nullptr));	// seed random number generator

	std::string s {};	// length 0
	s.reserve(64);		// reserve 64 characters

	// Fill string up with random lower case characters
	for (int count { 0 }; count < 64; ++count)
		s += 'a' + std::rand() % 26;

	std::cout << s;
}