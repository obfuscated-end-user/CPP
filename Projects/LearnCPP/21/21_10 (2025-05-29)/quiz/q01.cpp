// https://www.learncpp.com/cpp-tutorial/overloading-the-parenthesis-operator

/*
Write a class named MyString that holds a std::string. Overload operator<< to output the string. Overload operator() to return the substring that starts at the index of the first parameter (as a MyString). The length of the substring should be defined by the second parameter.

The following code should run:

```
int main()
{
	MyString s { "Hello, world!" };
	std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

	return 0;
}
```

This should print

```
world
```

Hint: You can use std::string::substr to get a substring of a std::string.
*/

#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

class MyString {
private:
	std::string m_string {};

public:
	MyString(std::string_view string={}) : m_string { string } {}

	MyString operator()(int start, int length) {
		assert(start >= 0);
		assert(start + length <= static_cast<int>(m_string.length()) && "MyString::operator(int, int): Substring is out of range");

		return MyString { m_string.substr(
			static_cast<std::string::size_type>(start),
			static_cast<std::string::size_type>(length)
		) };
	}

	friend std::ostream& operator<<(std::ostream& out, const MyString& s) {
		out << s.m_string;

		return out;
	}
};

int main() {
	MyString s { "Hello, world!" };
	std::cout << s(7, 5) << '\n';	// start at index 7 and return 5 characters

	return 0;
}