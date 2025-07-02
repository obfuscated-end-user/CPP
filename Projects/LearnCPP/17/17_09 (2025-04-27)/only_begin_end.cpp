// https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting

#include <iostream>

void printArray(const int* begin, const int* end) {
	for (; begin != end; ++begin) {
		std::cout << *begin << ' ';
	}

	std::cout << '\n';
}

int main() {
	constexpr int arr[] { 9, 7, 5, 3, 1 };
	
	const int* begin { arr };
	const int* end  { arr + std::size(arr) };

	printArray(begin, end);

	return 0;
}