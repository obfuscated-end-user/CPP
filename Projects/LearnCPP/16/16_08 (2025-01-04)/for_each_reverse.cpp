// https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each

#include <iostream>
#include <ranges>
#include <string_view>
#include <vector>

int main() {
	std::vector<std::string_view> words { "Albert", "Bobby", "Chad", "Dave" };	// sorted in alphabetical order
	
	for (const auto& word : std::views::reverse(words)) // create a reverse view
		std::cout << word << ' ';

	std::cout << '\n';

	return 0;
}