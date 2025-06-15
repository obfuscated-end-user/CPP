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

// Override print() for fully specialized StaticArray<char, 14>
template <>
void print(const StaticArray<char, 14>& array) {
    for (int count { 0 }; count < 14; ++count)
        std::cout << array[count];
}

int main() {
	// Declare a char array
    StaticArray<char, 14> char14 {};

    // Copy some data into it
    constexpr std::string_view hello1 { "Hello, world!" };
    std::copy_n(hello1.begin(), hello1.size(), char14.getArray());

    // Print the array
    print(char14);

    std::cout << '\n';

    // Declare a char array
    StaticArray<char, 12> char12{};

    // Copy some data into it
    constexpr std::string_view hello2 { "Hello, mom!" };
    std::copy_n(hello2.begin(), hello2.size(), char12.getArray());

    // Print the array
    print(char12);

	return 0;
}