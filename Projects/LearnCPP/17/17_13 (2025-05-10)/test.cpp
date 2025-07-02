#include <array>
#include <iostream>

int main() {
	// i know the cast isn't necessary
	constexpr std::array<std::size_t, 2> arr { static_cast<std::size_t>(1), static_cast<std::size_t>(2) };

	for (const auto& e : arr)
		std::cout << e << ' ';

	return 0;
}