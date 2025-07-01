// https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray

#include <array>
#include <iostream>

int main() {
	constexpr auto myArray1 { std::to_array<int, 5>({ 9, 7, 5, 3, 1 }) };	// Specify type and size
	constexpr auto myArray2 { std::to_array<int>({ 9, 7, 5, 3, 1 }) };		// Specify type only, deduce size
	constexpr auto myArray3 { std::to_array({ 9, 7, 5, 3, 1 }) };			// Deduce type and size

	constexpr auto shortArray { std::to_array<short>({ 9, 7, 5, 3, 1}) };
	std::cout << sizeof(shortArray[0]) << '\n';

	return 0;
}