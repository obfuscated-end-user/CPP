// https://www.learncpp.com/cpp-tutorial/class-template-specialization

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

// Explicit class template specialization for Storage<double>
// Note how redundant this is
template <>
class Storage<double> {
private:
	double m_value {};
public:
	Storage(double value) : m_value { value } {}

	void print();
};

// We're going to define this outside the class for reasons that will become obvious shortly
// This is a normal (non-specialized) member function definition (for member function print of specialized class Storage<double>)
void Storage<double>::print() {
	std::cout << std::scientific << m_value << '\n';
}

int main() {
	// Define some storage units
	Storage i { 5 };
	Storage d { 6.7 }; // uses explicit specialization Storage<double>

	// Print out some values
	i.print();	// calls Storage<int>::print (instantiated from Storage<T>)
	d.print();	// calls Storage<double>::print (called from explicit specialization of Storage<double>)
}