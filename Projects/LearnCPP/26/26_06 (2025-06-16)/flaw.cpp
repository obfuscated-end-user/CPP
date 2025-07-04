// https://www.learncpp.com/cpp-tutorial/partial-template-specialization-for-pointers

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

template<>
void Storage<double>::print() { // fully specialized for type double
	std::cout << std::scientific << m_value << '\n';
}

int main() {
	// Define some storage units
	Storage i { 5 };
	Storage d { 6.7 };	// will cause Storage<double> to be implicitly instantiated

	// Print out some values
	i.print();	// calls Storage<int>::print (instantiated from Storage<T>)
	d.print();	// calls Storage<double>::print (called from explicit specialization of Storage<double>::print())

	double e { 1.2 };
	double *ptr { &e };

	Storage s { ptr };
	s.print();	// what

	return 0;
}