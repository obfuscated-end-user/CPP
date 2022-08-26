// https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/

#include <iostream>

/* int main() {
    char character;
    std::cout << "Enter a single character: ";
    std::cin >> character;
    std::cout << "You entered \'" << character << "\' which has the ASCII code " << static_cast<int>(character) << std::endl;
    return 0;
} */


int main()
{
	std::cout << "Enter a single character: ";
	char c{};
	std::cin >> c;

	int ascii{ c };
	std::cout << "You entered '" << c << "', which has ASCII code " << ascii << ".\n";

	return 0;
}