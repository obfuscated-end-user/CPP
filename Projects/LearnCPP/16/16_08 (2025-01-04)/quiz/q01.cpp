// https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each

/*
Define a std::vector with the following names: “Alex”, “Betty”, “Caroline”, “Dave”, “Emily”, “Fred”, “Greg”, and “Holly”. Ask the user to enter a name. Use a range-based for loop to see if the name the user entered is in the array.

Sample output:

Enter a name: Betty
Betty was found.

Enter a name: Megatron
Megatron was not found.

Hint: Use std::string to hold the string the user inputs.
Hint: std::string_view is cheap to copy.
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int main() {
	std::vector<std::string_view> names { "Albert", "Betty", "Caroline", "Dave",
		"Emily", "Fred", "Greg", "Holly" };

	std::cout << "Enter a name: ";
	std::string username {};
	std::cin >> username;

	bool found { false };

	// We will be explicit about expecting `name` to be a std::string_view here
	// That way if `names` is ever changed to an expensive to copy type
	// (like std::string), we won't end up making expensive copies
	for (std::string_view name : names) {
		if (name == username) {
			found = true;
			break;
		}
	}

	if (found)
		std::cout << username << " was found.\n";
	else
		std::cout << username << " was not found.\n";

	return 0;
}