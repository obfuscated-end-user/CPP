// https://www.learncpp.com/cpp-tutorial/stdarray-and-enumerations

#include <array>
#include <iostream>
#include <string_view>

namespace Color {
	enum Type {
		black,
		red,
		blue,
		max_colors
	};

	// use sv suffix so std::array will infer type as std::string_view
	using namespace std::string_view_literals;	// for sv suffix
	constexpr std::array colorName { "black"sv, "red"sv, "blue"sv };

	// Make sure we've defined strings for all our colors
	static_assert(std::size(colorName) == max_colors);
};

constexpr std::string_view getColorName(Color::Type color) {
	return Color::colorName[color];
}

// Teach operator<< how to print a color
// std::ostream is the type of std::cout
// The return type and parameter type are references (to prevent copies from being made)!
std::ostream& operator<< (std::ostream& out, Color::Type color) {
	return out << getColorName(color);
}

int main() {
	// Use a for loop to iterate through all our colors
	for (int i = 0; i < Color::max_colors; ++i)
		std::cout << static_cast<Color::Type>(i) << '\n';

	return 0;
}