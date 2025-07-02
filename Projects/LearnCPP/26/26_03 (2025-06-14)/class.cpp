// https://www.learncpp.com/cpp-tutorial/function-template-specialization

#include <iostream>

template <typename T>
class Storage {
private:
	T m_value {};
public:
	Storage(T value) : m_value { value } {}

	void print() {
		std::cout << m_value << '\n';
	}
};

int main() {
	// Define some storage units
	Storage i { 5 };
	Storage d { 6.7 };

	// Print out some values
	i.print();
	d.print();
}