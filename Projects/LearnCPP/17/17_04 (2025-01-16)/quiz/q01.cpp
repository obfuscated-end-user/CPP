// https://www.learncpp.com/cpp-tutorial/stdarray-of-class-types-and-brace-elision

/*
Define a struct named Item that contains two members: std::string_view name and int gold. Define a std::array and initialize it with 4 Item objects. Use CTAD to deduce the element type and array size.
Show Hint
The program should print the following:
A sword costs 5 gold.
A dagger costs 3 gold.
A club costs 2 gold.
A spear costs 7 gold.
*/

#include <array>
#include <iostream>
#include <string_view>

struct Item {
	std::string_view name {};
	int gold {};
};

template <std::size_t N>
void printStore(const std::array<Item, N>& arr) {
	for (const auto& item : arr)
		std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
}

int main() {
	constexpr std::array store {	// CTAD, single braces due to brace elision
		Item { "sword",		5 },
		Item { "dagger",	3 },
		Item { "club",		2 },
		Item { "spear",		7 }
	};
	printStore(store);

	return 0;
}