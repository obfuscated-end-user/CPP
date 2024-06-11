// https://www.learncpp.com/cpp-tutorial/sorting-an-array-using-selection-sort

/*
Rewrite the selection sort code above to sort in descending order (largest numbers first). Although this may seem complex, it is actually surprisingly simple.*/

#include <iostream>
#include <iterator>
#include <utility>

int main() {
	int array[]{ 30, 50, 20, 10, 40 };
	constexpr int length{ static_cast<int>(std::size(array)) };

	for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex) {
		int largestIndex{ startIndex };

		for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex) {
			if (array[currentIndex] > array[largestIndex])
				largestIndex = currentIndex;
		}
		std::swap(array[startIndex], array[largestIndex]);
	}

	for (int index{ 0 }; index < length; ++index)
		std::cout << array[index] << ' ';
	std::cout << '\n';

	return 0;
}