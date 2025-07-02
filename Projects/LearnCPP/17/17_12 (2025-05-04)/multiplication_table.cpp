// https://www.learncpp.com/cpp-tutorial/multidimensional-c-style-arrays

#include <iostream>

int main() {

	constexpr int numRows { 10 };
	constexpr int numCols { 10 };

	// Declare a 10x10 array
	int product[numRows][numCols] {};

	// Calculate a multiplication table
	// We don't need to calc row and col 0 since mult by 0 is always 0
	for (std::size_t row { 1 }; row < numRows; ++row) {
		for (std::size_t col { 1 }; col < numCols; ++col)
			product[row][col] = static_cast<int>(row * col);
	}

	for (std::size_t row { 1 }; row < numRows; ++row) {
		for (std::size_t col { 1 }; col < numCols; ++col)
			std::cout << product[row][col] << '\t';

		std::cout << '\n';
	}

	return 0;
}