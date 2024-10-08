// https://www.learncpp.com/cpp-tutorial/constructors

/*
b) Update your answer to the previous question to use constructors with default parameters. Use as few constructors as possible.
*/

#include <iostream>
#include <string>
#include <string_view>

class Ball {
private:
    std::string m_color {};
    double m_radius {};

public:
    // set only m_radius
    Ball(double radius) {
        m_color = "black";
        m_radius = radius;
    }

    // set both
    Ball(std::string_view color = "black", double radius = 10.0) {
        m_color = color;
        m_radius = radius;
    }

    void print() {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }
};

int main() {
	Ball def{};
	def.print();

	Ball blue { "blue" };
	blue.print();

	Ball twenty { 20.0 };
	twenty.print();

	Ball blueTwenty { "blue", 20.0 };
	blueTwenty.print();

	return 0;
}