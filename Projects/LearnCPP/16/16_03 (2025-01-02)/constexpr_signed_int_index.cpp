// https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem

#include <iostream>
#include <vector>

int main() {
	std::vector prime { 2, 3, 4, 5, 7, 11 };

	std::cout << prime[3] << '\n';		// okay: 3 converted from int to std::size_t, not a narrowing conversion

	constexpr int index1 { 3 };			// constexpr
	std::cout << prime[index1] << '\n';	// okay: constexpr index implicitly converted to std::size_t, not a narrowing conversion

	std::size_t index2 { 3 };			// non-constexpr
	std::cout << prime[index2] << '\n'; // operator[] expects an index of type std::size_t, no conversion required

	int index3 { 3 };					// non-constexpr
	std::cout << prime[index3] << '\n'; // possible warning: index implicitly converted to std::size_t, narrowing conversion

	return 0;
}