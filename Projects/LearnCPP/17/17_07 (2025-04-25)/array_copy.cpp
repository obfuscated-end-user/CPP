// https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays

#include <algorithm> // for std::copy
#include <iostream>

int main() {
	int arr[] { 1, 2, 3 };
	int src[] { 4, 5, 6 };

	// Copy src into arr
	std::copy(std::begin(src), std::end(src), std::begin(arr));

	return 0;
}