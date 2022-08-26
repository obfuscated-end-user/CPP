// https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/

#include <iostream>

namespace a {
	int x{ 10 };
}

namespace b {
	int x{ 20 };
}

int main() {
	using namespace a;
	// using namespace b;
	std::cout << x << '\n';
	return 0;
}