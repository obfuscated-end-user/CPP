// https://www.learncpp.com/cpp-tutorial/multidimensional-stdarray

#include <array>
#include <iostream>

// An alias template for a two-dimensional std::array
template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

// Fetch the number of rows from the Row non-type template parameter
template <typename T, std::size_t Row, std::size_t Col>
constexpr int rowLength(const Array2d<T, Row, Col>&) {	// you can return std::size if you prefer
	return Row;
}

// Fetch the number of cols from the Col non-type template parameter
template <typename T, std::size_t Row, std::size_t Col>
constexpr int colLength(const Array2d<T, Row, Col>&) {	// you can return std::size if you prefer
	return Col;
}

int main() {
	// Define a two-dimensional array of int with 3 rows and 4 columns
	Array2d<int, 3, 4> arr {{
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 }
	}};

	std::cout << "Rows: " << arr.size() << '\n';	// get length of first dimension (rows)
	std::cout << "Cols: " << arr[0].size() << '\n';	// get length of second dimension (cols), undefined behavior if length of first dimension is zero!

	std::cout << '\n';

	std::cout << "Rows: " << rowLength(arr) << '\n';	// get length of first dimension (rows)
	std::cout << "Cols: " << colLength(arr) << '\n';	// get length of second dimension (cols)

	return 0;
}