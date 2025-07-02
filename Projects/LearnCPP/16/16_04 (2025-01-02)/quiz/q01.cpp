// https://www.learncpp.com/cpp-tutorial/passing-stdvector

/*
Write a function that takes two parameters: a std::vector and an index. If the index is out of bounds, print an error. If the index is in bounds, print the value of the element.

The following sample program should compile:

#include <iostream>
#include <vector>

// Write your printElement function here

int main()
{
	std::vector v1 { 0, 1, 2, 3, 4 };
	printElement(v1, 2);
	printElement(v1, 5);

	std::vector v2 { 1.1, 2.2, 3.3 };
	printElement(v2, 0);
	printElement(v2, -1);

	return 0;
}

and produce the following result:

The element has value 2
Invalid index
The element has value 1.1
Invalid index
*/

#include <iostream>
#include <vector>

// index needs to be an int, not a std::size_t, otherwise we won't be able to detect if the user passes in a negative index
template <typename T>
void printElement(const std::vector<T>& arr, int index) {
	if (index < 0 || index >= static_cast<int>(arr.size()))
		std::cout << "Invalid index\n";
	else
		std::cout << "The element has value " << arr[static_cast<std::size_t>(index)] << '\n';
}

int main() {
	std::vector v1 { 0, 1, 2, 3, 4 };
	printElement(v1, 2);
	printElement(v1, 5);

	std::vector v2 { 1.1, 2.2, 3.3 };
	printElement(v2, 0);
	printElement(v2, -1);

	return 0;
}