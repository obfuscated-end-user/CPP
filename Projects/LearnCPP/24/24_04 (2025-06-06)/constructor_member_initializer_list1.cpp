// https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes

#include <iostream>

class Base {
public:
	int m_id {};

	Base(int id=0) : m_id { id } {}

	int getID() const {
		return m_id;
	}
};

class Derived : public Base {
public:
	double m_cost {};

	Derived(double cost=0.0, int id=0) 
		: Base { id }   // Call Base(int) constructor with value id!
		, m_cost { cost } {}

	double getCost() const {
		return m_cost;
	}
};

int main() {
	Derived derived { 1.3, 5 }; // use Derived(double, int) constructor
	std::cout << "ID: " << derived.getID() << '\n';
	std::cout << "Cost: " << derived.getCost() << '\n';

	return 0;
}