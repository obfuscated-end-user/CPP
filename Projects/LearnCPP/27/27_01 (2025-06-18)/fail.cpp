// https://www.learncpp.com/cpp-tutorial/the-need-for-exceptions
#include <string_view>

int findFirstChar(std::string_view string, char ch) {
	// Step through each character in string
	for (std::size_t index { 0 }; index < string.length(); ++index) {
		// If the characer matches ch, return its index
		if (string[index] == ch)
			return index;
	}

	// If no match was found, return -1
	return -1;
}

double divide(int x, int y) {
	return static_cast<double>(x) / y;
}