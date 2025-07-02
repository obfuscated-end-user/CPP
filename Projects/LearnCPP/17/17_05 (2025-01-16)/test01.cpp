// https://www.learncpp.com/cpp-tutorial/arrays-of-references-via-stdreference_wrapper

#include <array>
#include <iostream>
#include <vector>

int main() {
	int x { 1 };
	int y { 2 };

	[[maybe_unused]] std::array valarr { x, y };	// an array of int values
	[[maybe_unused]] std::vector ptarr { &x, &y };	// a vector of int pointers

	return 0;
}