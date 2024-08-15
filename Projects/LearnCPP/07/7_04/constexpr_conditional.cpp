// https://www.learncpp.com/cpp-tutorial/constexpr-if-statements
// Moved to "8.4 — Constexpr if statements"

#include <iostream>

int main() {
	constexpr double gravity = 9.8;

	if constexpr (gravity == 9.8) // now using constexpr if
		std::cout << "Gravity is normal.\n";
	else
		std::cout << "We are not on Earth.\n";

	return 0;
}

/*
    you could erase all this shit and write:

    std::cout << "Gravity is normal.\n";

    ...which will do the exact same thing.
*/