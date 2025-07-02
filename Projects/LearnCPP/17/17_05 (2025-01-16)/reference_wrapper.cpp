// https://www.learncpp.com/cpp-tutorial/arrays-of-references-via-stdreference_wrapper

#include <array>
#include <functional>	// for std::reference_wrapper
#include <iostream>

int main() {
	int x { 1 };
	int y { 2 };
	int z { 3 };

	std::array<std::reference_wrapper<int>, 3> arr { x, y, z };

	arr[1].get() = 5;	// modify the object in array element 1

	std::cout << arr[1] << y << '\n';	// show that we modified arr[1] and y, prints 55

	std::reference_wrapper<int> ref1 { x };				// C++11
	auto ref2 { std::reference_wrapper<int> { x } };	// C++11

	auto ref { std::ref(x) };	// C++11, deduces to std::reference_wrapper<int>
	auto cref { std::cref(x) };	// C++11, deduces to std::reference_wrapper<const int>

	std::reference_wrapper ref3 { x };			// C++17
	auto ref4 { std::reference_wrapper { x }};	// C++17

	return 0;
}