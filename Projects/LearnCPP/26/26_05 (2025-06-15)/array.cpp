// https://www.learncpp.com/cpp-tutorial/partial-template-specialization

#include <iostream>

template <typename T, int size> // size is the expression parameter
class StaticArray {
private:
	// The expression parameter controls the size of the array
	T m_array[size] {};

public:
	T* getArray() {
		return m_array;
	}

	const T& operator[](int index) const {
		return m_array[index];
	}

	T& operator[](int index) {
		return m_array[index];
	}
};

template <typename T, int size>
void print(const StaticArray<T, size>& array) {
	for (int count { 0 }; count < size; ++count)
		std::cout << array[count] << ' ';
}

int main() {
	// declare an int array
	StaticArray<int, 4> int4 {};
	int4[0] = 0;
	int4[1] = 1;
	int4[2] = 2;
	int4[3] = 3;

	// Print the array
	print(int4);

	return 0;
}