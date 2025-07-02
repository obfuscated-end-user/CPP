// https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz

/*
Write definitions for the following. Use CTAD where possible (13.14 -- Class template argument deduction (CTAD) and deduction guides).
a) A std::vector initialized with the first 6 even numbers.
b) A constant std::vector initialized with the values 1.2, 3.4, 5.6, and 7.8.
c) A constant std::vector of std::string_view initialized with the names “Albert”, “Brad”, “Charles”, and “Dave”.
d) A std::vector with the single element value 12.
e) A std::vector with 12 int elements, initialized to the default values.
*/

#include <vector>
#include <string_view>

int main() {
	using namespace std::literals::string_view_literals;	// for sv suffix

	std::vector evens { 2, 4, 6, 8, 10, 12};
	const std::vector d { 1.2, 3.4, 5.6, 7.8 }; // reminder: std::vector can't be constexpr
	const std::vector names { "Albert"sv, "Brad"sv, "Charles"sv, "Dave"sv };	// sv suffix needed for CTAD to infer std::string_view
	std::vector v { 12 };
	std::vector<int> v2 (12);

	return 0;
}