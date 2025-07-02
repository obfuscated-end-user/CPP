// https://www.learncpp.com/cpp-tutorial/multidimensional-stdarray

#include <array>
#include <iostream>

template <typename T, std::size_t Row, std::size_t Col>
void printArray(const std::array<std::array<T, Col>, Row> &arr) {
	for (const auto& arow : arr) {	// get each array row
		for (const auto& e : arow)	// get each element of the row
			std::cout << e << ' ';
		std::cout << '\n';
	}
}

int main() {
	std::array<std::array<int, 4>, 3> arr {{
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 }
	}};

	printArray(arr);

	return 0;
}