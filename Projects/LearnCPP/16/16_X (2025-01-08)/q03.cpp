// https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz

/*
Write a function that takes a std::vector, returns a std::pair containing the indices of the elements with the min and max values in the array. The documentation for std::pair can be found here. Call the function on the following two vectors:
std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
The program should output the following:
With array ( 3, 8, 2, 5, 7, 8, 3 ):
The min element has index 2 and value 2
The max element has index 1 and value 8
With array ( 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 ):
The min element has index 4 and value 1.2
The max element has index 5 and value 8.8
*/

#include <iostream>
#include <vector>

template <typename T>
std::pair<std::size_t, std::size_t> findMinMaxIndices(const std::vector<T>& v) {
	std::size_t min { 0 };
	std::size_t max { 0 };
	for (std::size_t index { 0 }; index < v.size(); ++index) {
		if (v[index] < v[min])
			min = index;
		if (v[index] > v[max])
			max = index;
	}

	return { min, max };
}

template <typename T>
void printArray(const std::vector<T>& v) {
	bool comma { false };
	std::cout << "With array ( ";
	for (const auto& e : v) {
		if (comma)
			std::cout << ", ";

		std::cout << e;
		comma = true;
	}
	std::cout << " )\n";
}

int main() {
	std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
	printArray(v1);

	auto m1 { findMinMaxIndices(v1) };
	std::cout << "The min element has index " << m1.first << " and value " << v1[m1.first] << '\n';
	std::cout << "The max element has index " << m1.second << " and value " << v1[m1.second] << '\n';

	std::cout << '\n';

	std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
	printArray(v2);

	auto m2 { findMinMaxIndices(v2) };
	std::cout << "The min element has index " << m2.first << " and value " << v2[m2.first] << '\n';
	std::cout << "The max element has index " << m2.second << " and value " << v2[m2.second] << '\n';

	return 0;
}