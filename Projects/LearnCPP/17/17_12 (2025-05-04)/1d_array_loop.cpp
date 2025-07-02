// https://www.learncpp.com/cpp-tutorial/multidimensional-c-style-arrays

#include <iostream>

int main() {

	int arr[] { 1, 2, 3, 4, 5 };

	// for-loop with index
	for (std::size_t i { 0 }; i < std::size(arr); ++i)
		std::cout << arr[i] << ' ';

	std::cout << '\n';

	// range-based for-loop
	for (auto e: arr)
		std::cout << e << ' ';

	std::cout << '\n';

	return 0;
}