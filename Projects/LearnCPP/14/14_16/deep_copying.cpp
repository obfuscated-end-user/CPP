// https://www.learncpp.com/cpp-tutorial/shallow-vs-deep-copying

#include <cstring>
#include <cassert>
#include <iostream>

class MyString {
private:
    char* m_data;
    int m_length;

public:
    MyString(const char* source="") {
        assert(source);
        m_length = std::strlen(source) + 1;
        m_data = new char[m_length];

        for (int i = 0; i < m_length; ++i)
            m_data[i] = source[i];
    }
    // Copy constructor
    MyString(const MyString& source) {
        deepCopy(source);
    }

    ~MyString() {
        delete[] m_data;
    }

    char* getString() {
        return m_data;
    }
    int getLength() {
        return m_length;
    }

    // assumes m_data is initialized
    void deepCopy(const MyString& source) {
        // first we need to deallocate any value that this string is holding!
        delete[] m_data;

        // because m_length is not a pointer, we can shallow copy it
        m_length = source.m_length;

        // m_data is a pointer, so we need to deep copy it if it is non-null
        if (source.m_data) {
            // allocate memory for our copy
            m_data = new char[m_length];

            // do the copy
            for (int i{ 0 }; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        } else
            m_data = nullptr;
    }

    // Assignment operator
    MyString& operator=(const MyString& source) {
        // check for self-assignment
        if (this != &source)
            // now do the deep copy
            deepCopy(source);
        return *this;
    }
};

int main() {
    // remember that the "Hello, world!" is m_data, a const char*
    MyString hello { "Hello, world!" };

    {
        MyString copy { hello }; // use default copy constructor
    }

    std::cout << hello.getString() << '\n'; // kek

    return 0;
}