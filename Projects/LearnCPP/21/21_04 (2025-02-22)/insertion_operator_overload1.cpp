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
};

std::ostream& operator<<(std::ostream& out, const Point& point) {
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')'; // actual output done

    return out; // return std::ostream so we can chain calls to operator<<
}

int main() {
    const Point point1 { 2.0, 3.0, 4.0 };
    Point point2 { 2.0, 3.5, 4.0 };
    Point point3 { 6.0, 7.5, 8.0 };

    std::cout << point1 << ' ' << point2 << ' ' << point3 << '\n';

    return 0;
}