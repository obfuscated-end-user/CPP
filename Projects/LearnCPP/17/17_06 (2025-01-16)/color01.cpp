// https://www.learncpp.com/cpp-tutorial/stdarray-and-enumerations

#include <array>
#include <iostream>
#include <string>
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
	// We can index the array using the enumerator to get the name of the enumerator
	return Color::colorName[color];
}

// Teach operator<< how to print a color
// std::ostream is the type of std::cout
// The return type and parameter type are references (to prevent copies from being made)!
std::ostream& operator<< (std::ostream& out, Color::Type color) {
	return out << getColorName(color);
}

// Teach operator>> how to input a Color by name
// We pass color by non-const reference so we can have the function modify its value
std::istream& operator>> (std::istream& in, Color::Type& color) {
	std::string input {};
	std::getline(in >> std::ws, input);

	// Iterate through the list of names to see if we can find a matching name
	for (std::size_t index = 0; index < Color::colorName.size(); ++index) {
		if (input == Color::colorName[index]) {
			// If we found a matching name, we can get the numerator value based on its index
			color = static_cast<Color::Type>(index);
			return in;
		}
	}

	// We didn't find a match, so input must have been invalid
	// so we will set input stream to fail state
	in.setstate(std::ios_base::failbit);

	// On an extraction failure, operator >> zero-initializes fundamental types
	// Uncomment the following line to make this operator do the same thing
	// color = {};
	return in;
}

int main() {
	auto shirt { Color::blue };
	std::cout << "Your shirt is " << shirt << '\n';

	std::cout << "Enter a new color: ";
	std::cin >> shirt;

	if (!std::cin)
		std::cout << "Invalid\n";
	else
		std::cout << "Your shirt is now " << shirt << '\n';

	return 0;
}