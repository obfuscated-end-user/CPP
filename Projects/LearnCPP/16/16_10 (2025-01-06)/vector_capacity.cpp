// https://www.learncpp.com/cpp-tutorial/stdvector-resizing-and-capacity

#include <iostream>
#include <vector>

void printCapLen(const std::vector<int>& v) {
	std::cout << "Capacity: " << v.capacity() << " Length: " << v.size() <<'\n';
}

int main() {
	std::vector v { 0, 1, 2 };  // length is initially 3

	printCapLen(v);

	for (auto i : v)
		std::cout << i << ' ';
	std::cout << '\n';

	v.resize(5);	// resize to 5 elements

	printCapLen(v);

	for (auto i : v)
		std::cout << i << ' ';
	std::cout << '\n';

	return 0;
}