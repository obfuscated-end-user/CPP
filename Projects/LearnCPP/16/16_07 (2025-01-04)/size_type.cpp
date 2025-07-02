// https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions

#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr) {
	// typename keyword prefix required for dependent type
	for (typename std::vector<T>::size_type index { 0 }; index < arr.size(); ++index)
		std::cout << arr[index] << ' ';

	/*
	using arrayi = std::vector<int>;
	for (arrayi::size_type index { 0 }; index < arr.size(); ++index)

	// arr is some non-reference type
	for (decltype(arr)::size_type index { 0 }; index < arr.size(); ++index) // decltype(arr) resolves to std::vector<int>

	// arr can be a reference or non-reference type
	for (typename std::remove_reference_t<decltype(arr)>::size_type index{ 0 }; index < arr.size(); ++index)
	*/
}

int main() {
	std::vector arr1 { 1, 2, 3, 4, 5 };
	
	for (std::vector<int>::size_type index { 0 }; index < arr1.size(); ++index)
		std::cout << arr1[index] << ' ';

	std::vector arr2 { 9, 7, 5, 3, 1 };
	printArray(arr2);

	return 0;
}