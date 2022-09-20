// https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/

#include <iostream>
#include <random> // for std::mt19937, std::uniform_int_distribution, and std::random_device
#include <chrono> // for std::chrono

// WHOA NON CONST GLOBAL VARIABLES I HOPE YOUR PROGRAM BREAKS YOU FUCKING CUNT
namespace Random { // capital R to avoid conflicts with functions named random()
	std::mt19937 mt{ std::random_device{}() };
	int get(int min, int max) {
		std::uniform_int_distribution die{ min, max }; // we can create a distribution in any function that needs it
		return die(mt); // and then generate a random number from our global generator
	}
}

int main() {
	std::cout << Random::get(1, 6) << '\n';
	std::cout << Random::get(1, 10) << '\n';
	std::cout << Random::get(1, 20) << '\n';

	return 0;
}

/* int main() {
	std::mt19937 mt{ std::random_device{}() };

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count) {
		std::cout << die6(mt) << '\t'; // generate a roll of the die here

		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}
	return 0;
} */

/* int main() {
	// Seed our Mersenne Twister using the
	std::mt19937 mt{ static_cast<unsigned int>(
		std::chrono::steady_clock::now().time_since_epoch().count()
		) };

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count) {
		std::cout << die6(mt) << '\t'; // generate a roll of the die here

		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}
	return 0;
} */

/* int main() {
	std::mt19937 mt;
	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };
	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count) {
		std::cout << die6(mt) << '\t'; // generate a roll of the die here
		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}
	return 0;
} */

/* int main() {
	std::mt19937 mt; // Instantiate a 32-bit Mersenne Twister
	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count) {
		std::cout << mt() << '\t'; // generate a random number
		// If we've printed 5 numbers, start a new row
		if (count % 5 == 0)
			std::cout << '\n';
	}
	return 0;
} */