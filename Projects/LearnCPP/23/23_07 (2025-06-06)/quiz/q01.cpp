// https://www.learncpp.com/cpp-tutorial/stdinitializer_list

/*
Using the IntArray class above, implement an overloaded assignment operator that takes an initializer list.

The following code should run:

```
int main()
{
	IntArray array { 5, 4, 3, 2, 1 }; // initializer list
	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	return 0;
}
```

This should print:

```
5 4 3 2 1 
1 3 5 7 9 11
```
*/

#include <algorithm>		// for std::copy
#include <cassert>		  // for assert()
#include <initializer_list> // for std::initializer_list
#include <iostream>

class IntArray {
private:
	int m_length {};
	int* m_data {};

public:
	IntArray() = default;

	IntArray(int length) 
		: m_length { length }
		, m_data { new int[static_cast<std::size_t>(length)] {} } {}

	IntArray(std::initializer_list<int> list)	// allow IntArray to be initialized via list initialization
		: IntArray(static_cast<int>(list.size())) { // use delegating constructor to set up initial array
		// Now initialize our array from the list
		std::copy(list.begin(), list.end(), m_data);
	}

	~IntArray() {
		delete[] m_data;
		// we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
	}

	IntArray(const IntArray&) = delete; // to avoid shallow copies
	IntArray& operator=(const IntArray& list) = delete; // to avoid shallow copies

	IntArray& operator=(std::initializer_list<int> list) {
		// If the new list is a different size, reallocate it
		int length { static_cast<int>(list.size()) };
		if (length != m_length) {
			delete[] m_data;
			m_length = length;
			m_data = new int[list.size()] {};
		}

		// Now initialize our array from the list
		std::copy(list.begin(), list.end(), m_data);

		return *this;
	}

	int& operator[](int index) {
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const {
		return m_length;
	}
};


int main() {
	IntArray array { 5, 4, 3, 2, 1 }; // initializer list
	for (int count { 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (int count { 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	return 0;
}