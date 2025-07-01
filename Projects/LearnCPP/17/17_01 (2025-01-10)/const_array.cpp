// https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray

#include <array>

int main() {
	const std::array<int, 5> prime1 { 2, 3, 5, 7, 11 };
	constexpr std::array<int, 5> prime2 { 2, 3, 5, 7, 11 };

	return 0;
}