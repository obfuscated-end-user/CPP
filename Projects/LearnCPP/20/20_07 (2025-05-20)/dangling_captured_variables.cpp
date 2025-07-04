// https://www.learncpp.com/cpp-tutorial/lambda-captures

#include <iostream>
#include <string>

// returns a lambda
auto makeWalrus(const std::string& name) {
	// Capture name by reference and return the lambda.
	return [&]() {
		std::cout << "I am a walrus, my name is " << name << '\n';	// undefined behavior
	};
}

int main() {
	// Create a new walrus whose name is Roofus.
	// sayName is the lambda returned by makeWalrus.
	auto sayName { makeWalrus("Roofus") };

	// Call the lambda function that makeWalrus returned.
	sayName();

	return 0;
}