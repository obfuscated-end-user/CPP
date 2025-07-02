// https://www.learncpp.com/cpp-tutorial/recursion

#include <iostream>
#include <vector>

// h/t to potterman28wxcv for a variant of this code
// count is now a std::size_t to make indexing the std::vector easier
int fibonacci(std::size_t count) {
	// We'll use a static std::vector to cache calculated results
	static std::vector results { 0, 1 };

	// If we've already seen this count, then use the cached result
	if (count < std::size(results))
		return results[count];

	// Otherwise calculate the new result and add it
	results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
	return results[count];
}

int main() {
	for (int count { 0 }; count < 13; ++count)
		std::cout << fibonacci(static_cast<std::size_t>(count)) << ' ';

	return 0;
}