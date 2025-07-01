// https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray

#include <array>
#include <iostream>

int main() {
	constexpr std::array a1 { 9, 7, 5, 3, 1 };	// The type is deduced to std::array<int, 5>
	constexpr std::array a2 { 9.7, 7.31 };		// The type is deduced to std::array<double, 2>

	// constexpr std::array<int> a3 { 9, 7, 5, 3, 1 };	// error: too few template arguments (length missing)
	// constexpr std::array<5> a3 { 9, 7, 5, 3, 1 };	// error: too few template arguments (type missing)

	return 0;
}