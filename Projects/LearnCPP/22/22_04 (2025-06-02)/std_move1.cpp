// https://www.learncpp.com/cpp-tutorial/stdmove

#include <iostream>
#include <string>
#include <utility>	// for std::move

template <typename T>
void mySwapMove(T& a, T& b) {
	T tmp { std::move(a) };	// invokes move constructor
	a = std::move(b);		// invokes move assignment
	b = std::move(tmp);		// invokes move assignment
}

int main() {
	std::string x { "abc" };
	std::string y { "de" };

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	mySwapMove(x, y);

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	return 0;
}