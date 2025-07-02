// https://www.learncpp.com/cpp-tutorial/chapter-25-summary-and-quiz

/*
2a) Create an abstract class named Shape. This class should have three functions: a pure virtual print function that takes and returns a std::ostream&, an overloaded operator<< and an empty virtual destructor.
*/

#include <iostream>

class Shape {
public:
	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape& p) {
		return p.print(out);
	}

	virtual ~Shape() = default;
};