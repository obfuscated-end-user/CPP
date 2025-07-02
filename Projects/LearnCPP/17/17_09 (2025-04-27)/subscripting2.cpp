// https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting

#include <iostream>

int main() {
	const int arr[] { 3, 2, 1 };

	// First, let's use subscripting to get the address and valus of our array elements
	std::cout << &arr[0] << ' ' << &arr[1] << ' ' << &arr[2] << '\n';
	std::cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
	
	// Now let's do the equivalent using pointer arithmetic
	std::cout << arr << ' ' << (arr + 1) << ' ' << (arr + 2) << '\n';
	std::cout << *arr << ' ' << *(arr + 1) << ' ' << *(arr + 2) << '\n';

	return 0;
}