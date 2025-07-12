// https://www.learncpp.com/cpp-tutorial/stdstring-length-and-capacity

#include <iostream>
#include <string>

int main() {
	std::string s1 { "012345678" };
	std::cout << s1.length() << '\n';

	std::string string1 { "Not Empty" };
	std::cout << (string1.empty() ? "true" : "false") << '\n';
	std::string string2;	// empty
	std::cout << (string2.empty() ? "true" : "false") << '\n';

	std::string s2 { "MyString" };
	std::cout << s2.max_size() << '\n';

	std::string s3 { "01234567" };
	std::cout << "Length: " << s3.length() << '\n';
	std::cout << "Capacity: " << s3.capacity() << '\n';

	return 0;
}