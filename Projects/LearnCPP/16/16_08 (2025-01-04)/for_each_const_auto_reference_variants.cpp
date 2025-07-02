// https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each

#include <iostream>
#include <string_view>
#include <vector>

int main() {
	std::vector<std::string_view> words1 { "peter", "likes", "frozen", "yogurt" };	// elements are type std::string_view

	for (auto word : words1) // We normally pass string_view by value, so we'll use auto here
		std::cout << word << ' ';
	std::cout << '\n';

	std::vector<std::string> words2 { "peter", "likes", "frozen", "yogurt" };	// obvious we should update this
	for (auto word : words2)	// Probably not obvious we should update this too
		std::cout << word << ' ';

	return 0;
}