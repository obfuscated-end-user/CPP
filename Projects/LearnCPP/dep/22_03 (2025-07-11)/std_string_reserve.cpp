// https://www.learncpp.com/cpp-tutorial/stdstring-length-and-capacity

#include <iostream>
#include <string>

int main() {
	std::string s { "01234567" };
	std::cout << "Length: " << s.length() << '\n';
	std::cout << "Capacity: " << s.capacity() << '\n';

	s.reserve(200);
	std::cout << "Length: " << s.length() << '\n';
	std::cout << "Capacity: " << s.capacity() << '\n';

	s.reserve();
	std::cout << "Length: " << s.length() << '\n';
	std::cout << "Capacity: " << s.capacity() << '\n';

	return 0;
}