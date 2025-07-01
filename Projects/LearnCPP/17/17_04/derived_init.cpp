// https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes

#include <iostream>

class Base {
private:
	int m_id;

public:
	Base(int id=0): m_id { id } {}

	int getId() const {
		return m_id;
	}
};

class Derived: public Base {
private:
	double m_cost;

public:
	// Call Base(int) constructor with value id
	Derived(double cost=0.0, int id=0) : Base { id }, m_cost { cost } {}

	double getCost() const {
		return m_cost;
	}
};

int main() {
	Derived derived { 1.3, 5 };	// use Derived(double, int) constructor
	std::cout << "Id: " << derived.getId() << '\n';
	std::cout << "Cost: " << derived.getCost() << '\n';

	return 0;
}