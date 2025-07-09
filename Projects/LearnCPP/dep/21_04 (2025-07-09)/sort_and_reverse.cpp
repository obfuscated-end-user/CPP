// https://www.learncpp.com/cpp-tutorial/stl-algorithms-overview

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> vect { 7, -3, 6, 2, -5, 0, 4 };

	// sort the vector
	std::sort(vect.begin(), vect.end());

	for (int i : vect)
		std::cout << i << ' ';

	std::cout << '\n';

	// reverse the vector
	std::reverse(vect.begin(), vect.end());

	for (int i : vect)
		std::cout << i << ' ';

	std::cout << '\n';

	return 0;
}