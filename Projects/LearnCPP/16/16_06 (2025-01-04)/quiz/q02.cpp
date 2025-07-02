// https://www.learncpp.com/cpp-tutorial/arrays-and-loops

/*
Update your code for the prior quiz solution so that the following program compiles and has the same output:

#include <iostream>
#include <vector>

// Implement printArray() here

int main()
{
	std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

	printArray(arr); // use function template to print array

	return 0;
}
*/

#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr) {
	for (std::size_t index { 0 }; index < arr.size(); ++index)
		std::cout << arr[index] << ' ';

	if (arr.size() > 0)
		std::cout << '\n';
}

int main() {
	std::vector arr { 4, 6, 7, 3, 8, 2, 1, 9 };

	printArray(arr);

	return 0;
}