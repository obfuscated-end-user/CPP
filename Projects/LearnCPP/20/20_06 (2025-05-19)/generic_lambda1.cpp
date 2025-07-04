// https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main() {
	constexpr std::array months {	// pre-C++17 use std::array<const char*, 12>
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};

	// Search for two consecutive months that start with the same letter.
	const auto sameLetter { std::adjacent_find(months.begin(), months.end(),
											[](const auto& a, const auto& b) {
												return a[0] == b[0];
											}) };

	// Make sure that two months were found.
	if (sameLetter != months.end()) {
		// std::next returns the next iterator after sameletter
		std::cout << *sameLetter << " and " << *std::next(sameLetter)
				<< " start with the same letter\n";
	}

	// Count how many months consist of 5 letters
	// const or constexpr (C++20)
	constexpr auto fiveLetterMonths { std::count_if(months.begin(), months.end(),
												[](std::string_view str) {
													return str.length() == 5;
												}) };

	std::cout << "There are " << fiveLetterMonths << " months with 5 letters\n";

	return 0;
}