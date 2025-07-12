// https://www.learncpp.com/cpp-tutorial/stdstring-length-and-capacity

#include <iostream>
#include <string>

int main() {
	std::string s1 { "0123456789abcde" };
	std::cout << "Length: " << s1.length() << '\n';
	std::cout << "Capacity: " << s1.capacity() << '\n';

	// Now add a new character
	s1 += "f";
	std::cout << "Length: " << s1.length() << '\n';
	std::cout << "Capacity: " << s1.capacity() << '\n';

	return 0;
}