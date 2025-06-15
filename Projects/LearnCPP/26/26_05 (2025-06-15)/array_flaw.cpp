// https://www.learncpp.com/cpp-tutorial/partial-template-specialization

#include <algorithm>
#include <iostream>
#include <string_view>

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
	// Declare a char array
    StaticArray<char, 14> char14 {};

    // Copy some data into it
    constexpr std::string_view hello { "Hello, world!" };
    std::copy_n(hello.begin(), hello.size(), char14.getArray());

    // Print the array
    print(char14);

	return 0;
}