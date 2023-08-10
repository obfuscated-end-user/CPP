// https://www.learncpp.com/cpp-tutorial/chapter-14-comprehensive-quiz

#include <iostream>
#include <cassert>

class IntArray {
private:
    int m_length = 0;
    // int pointer because you know, arrays and shit in c++
    int* m_array = nullptr;

public:
    explicit IntArray(int length): m_length {length} {
        // prevents really stupid shit
        assert(length > 0 && "IntArray length should be a positive integer");
        // reserve space of that size
        m_array = new int[m_length] {};
    }

    // copy constructor
    IntArray(const IntArray& array): m_length {array.m_length} {
        // make space
        m_array = new int[m_length];

        // copy elements from original array to the new one
        for (int i = 0; i < array.m_length; ++i)
            m_array[i] = array.m_array[i];
    }

    // destructor
    ~IntArray() {
        delete[] m_array;
    }

    // for std::cout
    friend std::ostream& operator<<(std::ostream& out, const IntArray& array) {
        for (int i = 0; i < array.m_length; ++i)
            out << array.m_array[i] << ' ';
        return out;
    }

    // array subscript []
    int& operator[](const int index) {
        assert(index >= 0);
        assert(index < m_length);
        return m_array[index];
    }

    // this does a deep copy
    IntArray& operator=(const IntArray& array) {
        if (this == &array)
            return *this;
        
        delete[] m_array;

        m_array = new int[m_length];

        for (int i = 0; i < array.m_length; ++i)
            m_array[i] = array.m_array[i];

        return *this;
    }
};

IntArray fillArray() {
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main() {
	IntArray a { fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n'; // what the fuck?

	return 0;
}