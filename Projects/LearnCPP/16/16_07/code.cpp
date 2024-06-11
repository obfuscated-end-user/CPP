// https://www.learncpp.com/cpp-tutorial/stdinitializer_list

#include <cassert>
#include <initializer_list>
#include <iostream>

class IntArray {
private:
	int m_length;
	int* m_data;

public:
	IntArray() = default;
	IntArray(int length): m_length{length}, m_data{new int[length]{}} {}

	IntArray(std::initializer_list<int> list): IntArray(static_cast<int>(list.size())){
		int count = 0;
		for (auto element : list) {
			m_data[count] = element;
			++count;
		}
	}

	~IntArray() {
		delete[] m_data;
	}

//	IntArray(const IntArray&) = delete; // to avoid shallow copies
//	IntArray& operator=(const IntArray& list) = delete; // to avoid shallow copies

	int& operator[](int index) {
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const {
        return m_length;
    }
};

int main() {
	IntArray array{};
	array = { 1, 3, 5, 7, 9, 11 }; // Here's our list assignment statement

	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';   // garbage

	return 0;
}