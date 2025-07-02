// https://www.learncpp.com/cpp-tutorial/arrays-and-loops

/*
Write a short program that prints the elements of the following vector to the screen using a loop:

#include <iostream>
#include <vector>

int main()
{
	std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

	// Add your code here

	return 0;
}

The output should look like this:

4 6 7 3 8 2 1 9
*/

#include <iostream>
#include <vector>

int main() {
	std::vector arr { 4, 6, 7, 3, 8, 2, 1, 9 };
	for (std::size_t index { 0 }; index < arr.size(); ++index)
		std::cout << arr[index] << ' ';

	if (arr.size() > 0)
		std::cout << '\n';

	return 0;
}