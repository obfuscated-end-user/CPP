// https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators

#include <iostream>

class Point {
private:
	double m_x {};
	double m_y {};
	double m_z {};

public:
	Point (double x=0.0, double y=0.0, double z=0.0)
		: m_x { x }, m_y { y }, m_z { z } {}

	friend std::ostream& operator<<(std::ostream& out, const Point& point);
	friend std::istream& operator>>(std::istream& in, Point& point);
};

std::ostream& operator<<(std::ostream& out, const Point& point) {
	// Since operator<< is a friend of the Point class, we can access Point's members directly.
	out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

	return out;
}

// note that point must be non-const so we can modify the object
std::istream& operator>>(std::istream& in, Point& point) {
	double x {};
	double y {};
	double z {};

	/* if (in >> x >> y >> z)			// if all extractions succeed
		point = Point { x, y, z };	// overwrite our existing point */

	/* in >> x >> y >> z;
	point = in ? Point { x, y, z } : Point {}; */

	in >> x >> y >> z;
	if (x < 0.0 || y < 0.0 || z < 0.0)			// if any extractable input is negative
		in.setstate(std::ios_base::failbit);	// set failure mode manually
	point = in ? Point { x, y, z } : Point {};

	return in;
}

int main() {
	std::cout << "Enter a point: ";

	Point point { 1.0, 2.0, 3.0 }; // non-zero test data
	std::cin >> point;

	std::cout << "You entered: " << point << '\n';

	return 0;
}