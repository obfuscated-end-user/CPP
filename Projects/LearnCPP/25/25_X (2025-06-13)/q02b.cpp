// https://www.learncpp.com/cpp-tutorial/chapter-25-summary-and-quiz

/*
2b) Derive two classes from Shape: a Triangle, and a Circle. The Triangle should have 3 Points as members. The Circle should have one center Point, and an integer radius. Override the print() function so the following program runs:

```
int main()
{
	Circle c{ Point{ 1, 2 }, 7 };
	std::cout << c << '\n';

	Triangle t{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }};
	std::cout << t << '\n';

	return 0;
}
```

This should print:

```
Circle(Point(1, 2), radius 7)
Triangle(Point(1, 2), Point(3, 4), Point(5, 6))
```

Here’s a Point class you can use:

```
class Point
{
private:
	int m_x{};
	int m_y{};

public:
	Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};
```
*/

#include <iostream>

class Point {
private:
	int m_x {};
	int m_y {};

public:
	Point(int x, int y) : m_x { x }, m_y { y } {}

	friend std::ostream& operator<<(std::ostream& out, const Point& p) {
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

class Shape {
public:
	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape& p) {
		return p.print(out);
	}

	virtual ~Shape() = default;
};

class Triangle : public Shape {
private:
	Point m_p1;
	Point m_p2;
	Point m_p3;

public:
	Triangle(const Point& p1, const Point& p2, const Point& p3)
		: m_p1 { p1 }, m_p2 { p2 }, m_p3 { p3 } {}

	std::ostream& print(std::ostream& out) const override {
		return out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ')';
	}
};

class Circle : public Shape {
private:
	Point m_center;
	int m_radius {};

public:
	Circle(const Point& center, int radius)
		: m_center { center }, m_radius { radius } {}

	std::ostream& print(std::ostream& out) const override {
		return out << "Circle(" << m_center << ", radius " << m_radius << ')';
	}
};

int main() {
	Circle c { Point { 1, 2 }, 7 };
	std::cout << c << '\n';

	Triangle t { Point { 1, 2 }, Point { 3, 4 }, Point { 5, 6 }};
	std::cout << t << '\n';

	return 0;
}