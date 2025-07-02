// https://www.learncpp.com/cpp-tutorial/stdinitializer_list

#include <cassert>
#include <initializer_list>
#include <iostream>

class IntArray {
private:
	int m_length;
	int* m_data;

public:
	// constructors you're used to seeing
	IntArray() = default;
	IntArray(int length): m_length { length }, m_data { new int[length] {} } {}

	// allow IntArray to use an std::initializer_list
	// use a delegating constructor to do the shortcut thing (the IntArray(static_cast<int>(list.size()) part)
	IntArray(std::initializer_list<int> list): IntArray(static_cast<int>(list.size())) {
		int count = 0;
		for (auto element : list) {
			m_data[count] = element;
			++count;
		}
	}

	~IntArray() {
		delete[] m_data;
	}

	// both of these avoid shallow copies to be made
	IntArray(const IntArray&) = delete;
	IntArray& operator=(const IntArray& list) = delete;

	int& operator[](int index) {
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const {
		return m_length;
	}
};

int main() {
	// IntArray array{ 5, 4, 3, 2, 1 };
	IntArray array = { 5, 4, 3, 2, 1 };	// initializer list
	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	IntArray a1(5);	// uses IntArray(int), allocates an array of size 5
	IntArray a2 { 5 }; // uses IntArray<std::initializer_list<int>, allocates array of size 1

	return 0;
}

/*
When initializing a container that has a list constructor:
	Use brace initialization when intending to call the list constructor (e.g. because your initializers are element values)
	Use direct initialization when intending to call a non-list constructor (e.g. because your initializers are not element values).
*/