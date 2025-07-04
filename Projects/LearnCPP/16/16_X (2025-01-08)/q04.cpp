// https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz

/*
Modify the prior program so that the user can enter as many integers as they like. Stop accepting input when the user enters -1.
Print the vector and find the min and max elements.
When run with the input 3 8 5 2 3 7 -1, the program should produce the following output:
Enter numbers to add (use -1 to stop): 3 8 5 2 3 7 -1
With array ( 3, 8, 5, 2, 3, 7 ):
The min element has index 3 and value 2
The max element has index 1 and value 8
Do something reasonable when the user enters -1 as the first input.
*/

#include <iostream>
#include <limits>
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
	for (const auto& e: v) {
		if (comma)
			std::cout << ", ";

		std::cout << e;
		comma = true;
	}
	std::cout << " ):\n";
}

int main() {
	std::vector<int> v1 {};
	std::cout << "Enter numbers to add (use -1 to stop): ";

	while (true) {
		int input {};
		std::cin >> input;
		if (input == -1)
			break;

		if (!std::cin) {	// if the previous extraction failed
			std::cin.clear();	// put us back in 'normal' operation mode
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
			continue;
		}

		v1.push_back(input);
	}

	// If the array is empty
	if (v1.size() == 0) {
		std::cout << "The array has no elements\n";
	} else {
		printArray(v1);

		auto m1 { findMinMaxIndices(v1) };
		std::cout << "The min element has index " << m1.first << " and value " << v1[m1.first] << '\n';
		std::cout << "The max element has index " << m1.second << " and value " << v1[m1.second] << '\n';
	}

	return 0;
}