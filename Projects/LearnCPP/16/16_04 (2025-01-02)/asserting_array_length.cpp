// https://www.learncpp.com/cpp-tutorial/passing-stdvector

#include <iostream>
#include <vector>

template <typename T>
void printElement3(const std::vector<T>& arr) {
	std::cout << arr[3] << '\n';
}

int main() {
	std::vector arr1 { 9, 7, 5, 3, 1 };
	printElement3(arr1);

	std::vector arr2 { 9, 7 };	// a 2-element array (valid indexes 0 and 1)
	printElement3(arr2);

	return 0;
}