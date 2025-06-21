// https://www.learncpp.com/cpp-tutorial/stream-states-and-input-validation/#comment-571052

#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>

bool containsInvalidNameCharacters(std::string_view input) {
	return !std::ranges::all_of(
		input,
		[](char x) { return std::isalpha(x) || std::isspace(x); }
	);
}

auto spaceCount(std::string_view input) {
	return std::ranges::count_if(
		input,
		[](char x) { return std::isspace(x); }
	);
}

bool invalidName(std::string_view input) {
	return (input.length() < 2) // New
		|| (containsInvalidNameCharacters(input))
		|| (spaceCount(input) > 1); // New
}

int main() {
	std::string input {};

	do {
		std::cout << "Enter your name: ";

		std::getline(std::cin, input);
	} while (invalidName(input));

	std::cout << "Hello " << input << "!\n";
}