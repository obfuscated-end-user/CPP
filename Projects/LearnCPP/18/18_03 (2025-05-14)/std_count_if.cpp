// https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

bool containsNut(std::string_view str) {
	return str.find("nut") != std::string_view::npos;
}

int main() {
	std::array<std::string_view, 5> arr { "apple", "banana", "walnut", "lemon", "peanut" };

	auto nuts { std::count_if(arr.begin(), arr.end(), containsNut) };

	std::cout << "Counted " << nuts << " nut(s)\n";

	return 0;
}