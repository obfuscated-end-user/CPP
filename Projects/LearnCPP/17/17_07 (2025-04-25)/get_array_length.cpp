// https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays

#include <cstddef>  // for std::size_t
#include <iostream>

template <typename T, std::size_t N>
constexpr std::size_t length(const T(&)[N]) noexcept {
	return N;
}

int main() {
	int array1[] { 1, 1, 2, 3, 5, 8, 13, 21 };
	std::cout << "The array has: " << length(array1) << " elements\n";

	int array2[8] {};
	std::cout << "The array has: " << sizeof(array2) / sizeof(array2[0]) << " elements\n";

	return 0;
}