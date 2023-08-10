// https://www.learncpp.com/cpp-tutorial/chapter-13-comprehensive-quiz
// starting from now, i won't write the questions here inside multiline comments
// you can check for the correct (read: "preferred") answers on the link above
// my code may not be the best, but hey, at least it works

#include <iostream>
#include <cmath>

// a) Write a class named Point2d. Point2d should contain two member variables of type double: m_x, and m_y, both defaulted to 0.0. Provide a constructor and a print function.
class Point2d {
public:
    double m_x;
    double m_y;

    // smaller version
    Point2d(double m_x = 0.0, double m_y = 0.0):
        m_x{m_x}, m_y{m_y}{}

    // longer version, does the exact same thing
    /* Point2d(double m_x, double m_y) {
        this->m_x = m_x;
        this->m_y = m_y;
    }

    Point2d() {
        this->m_x = 0;
        this->m_y = 0;
    } */

    void print() const {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    // b) Now add a member function named distanceTo that takes another Point2d as a parameter, and calculates the distance between them. Given two points (x1, y1) and (x2, y2), the distance between them can be calculated as std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)). The std::sqrt function lives in header cmath.
    // may be possibly done with std::exp()?
    // i kept it just because
    double distanceTo(const Point2d &point2d) {
        return std::sqrt((point2d.m_x - this->m_x) * (point2d.m_x - this->m_x) + (point2d.m_y - this->m_y) * (point2d.m_y - this->m_y));
    }

    friend double distanceFrom(const Point2d &point1, const Point2d &point2);
};

// c) Change function distanceTo from a member function to a non-member friend function that takes two Points as parameters. Also rename it “distanceFrom”.
double distanceFrom(const Point2d &point1, const Point2d &point2) {
    return std::sqrt((point1.m_x - point2.m_x) * (point1.m_x - point2.m_x) + (point1.m_y - point2.m_y) * (point1.m_y - point2.m_y));
}

int main() {
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "(distanceTo) Distance between two points: " << first.distanceTo(second) << '\n';
    std::cout << "(distanceFrom) Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}