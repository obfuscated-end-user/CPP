// https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator

#include <algorithm>	// for std::max and std::copy_n
#include <iostream>

class MyString {
private:
	char* m_data {};
	int m_length {};

public:
	MyString(const char* data=nullptr, int length=0)
		: m_length { std::max(length, 0) } {
		if (length) {
			m_data = new char[static_cast<std::size_t>(length)];
			std::copy_n(data, length, m_data);	// copy length elements of data into m_data
		}
	}

	~MyString() {
		delete[] m_data;
	}

	MyString(const MyString&) = default;	// some compilers (gcc) warn if you have pointer members but no declared copy constructor

	// Overloaded assignment
	MyString& operator=(const MyString& str);

	friend std::ostream& operator<<(std::ostream& out, const MyString& s);
};

std::ostream& operator<<(std::ostream& out, const MyString& s) {
	out << s.m_data;
	return out;
}

MyString& MyString::operator=(const MyString& str) {
	// self-assignment check
	if (this == &str)
		return *this;

	// if data exists in the current string, delete it
	if (m_data)
		delete[] m_data;
	
	m_length = str.m_length;
	m_data = nullptr;

	// allocate a new array of the appropriate length
	if (m_length)
		m_data = new char[static_cast<std::size_t>(str.m_length)];

	std::copy_n(str.m_data, m_length, m_data);	// copies m_length elements of str.m_data into m_data

	// return the existing object so we can chain this operator
	return *this;
}

int main() {
	MyString bob("Bob", 5);	// Meet Bob
	MyString employee;
	employee = bob;		 	// Bob is our newest employee
	std::cout << employee;	// say your name, employee

	bob = bob;
	std::cout << employee;

	return 0;
}