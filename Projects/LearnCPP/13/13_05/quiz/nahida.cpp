// https://www.learncpp.com/cpp-tutorial/constructors

/*
Question #1

a) Write a class named Ball. Ball should have two private member variables with default values: m_color (“black”) and m_radius (10.0). Ball should provide constructors to set only m_color, set only m_radius, set both, or set neither value. For this quiz question, do not use default parameters for your constructors. Also write a function to print out the color and radius of the ball.

The following sample program should compile:

int main()
{
	Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	return 0;
}

and produce the result:

color: black, radius: 10
color: blue, radius: 10
color: black, radius: 20
color: blue, radius: 20

*/

#include <iostream>
#include <string>

class Ball {
private:
    std::string m_color { "black" };
    double m_radius { 10.0 };

public:
    // set only m_color
    Ball(std::string color) {
        m_color = color;
    }
    // set only m_radius
    Ball(double radius) {
        m_radius = radius;
    }

    // set both
    Ball(std::string color, double radius) {
        m_color = color;
        m_radius = radius;
    }

    // set neither value
    Ball() {};

    void print() {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }
};

int main() {
	Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	return 0;
}