// https://www.learncpp.com/cpp-tutorial/container-classes

#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert>

class IntArray {
private:
    int m_length;
    int* m_data;

public:
    IntArray() = default;

    IntArray(int length): m_length{length} {
        assert(length >= 0);
        if (length > 0)
            // make new array
            m_data = new int[length]{};
    }

    // copy constructor
    IntArray(const IntArray& a) {
        reallocate(a.getLength());
        for (int index = 0; index < m_length; ++index)
            m_data[index] = a.m_data[index];
    }

    ~IntArray() {
        delete[] m_data;
    }

    int& operator[](int index) {
        // prevents something stupid like IntArray[-1239923]
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    IntArray& operator=(const IntArray& a) {
        // self-assignment check
        if (&a == this)
            return *this;

        // set the size of the new array
        reallocate(a.getLength());

        // copy
        for (int index = 0; index < m_length; ++index)
            m_data[index] = a.m_data[index];

        return *this;
    }

    void erase() {
        delete[] m_data;
        // setting m_data to nullptr is important
        m_data = nullptr;
        m_length = 0;
    }

    // this resizes the array, this is fast
    void reallocate(int newLength) {
        // delete any existing elements
        erase();

        // if array is empty now, return here and ignore the code below
        if (newLength <= 0)
            return;

        // else allocate new
        m_data = new int[newLength];
        m_length = newLength;
    }

    // this also resizes the array, but is slow
    void resize(int newLength) {
        // if same size, do nothing
        if (newLength == m_length)
            return;

        // if 0, delete it
        if (newLength <= 0) {
            erase();
            return;
        }

        // hard part lmao
        // allocate new array
        int* data = new int[newLength];

        // figure out how many elements to copy from the existing array to the new array
        if (m_length > 0) {
            // determine which array has more items
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;
            // add elements to new array
            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        // usual thing when it comes to pointer magic
        delete[] m_data;
        // make m_data point to the new array
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index) {
        // check if index is valid
        assert(index >= 0 && index <= m_length);

        // create a new array that is one element larger the old array, because, you know, you're inserting a new element
        int* data = new int[m_length + 1];

        // copy everything into the new array
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        // insert the value to be inserted at that index
        data[index] = value;

        // copy all of the values after the inserted element
        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        // delete the old array, and use the new one instead
        delete[] m_data;
        m_data = data;
        // new array is one element larger that the old array, so we have to update this too
        ++m_length;
    }

    void remove(int index) {
        assert(index >= 0 && index <= m_length);

        // if there is only one element, delete the array and exit this function
        if (m_length == 1) {
            erase();
            return;
        }

        // create a new array, but one element less than the old array, because you're removing an element
        int* data = new int [m_length - 1];

        // copy everything into the new array
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        // copy values after the removed element
        for (int after = index + 1; after < m_length; ++after)
            data[after - 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        // array one element smaller than the old one
        --m_length;
    }

    void insertAtBeginning(int value) {
        insertBefore(value, 0);
    }

    void insertAtEnd(int value) {
        insertBefore(value, m_length);
    }

    int getLength() const {
        return m_length;
    }
};

#endif