// https://www.learncpp.com/cpp-tutorial/overloading-operators-and-function-templates

#include <iostream>

template <typename T>
T average(const T* myArray, int numValues) {
    T sum = 0;
    for (int count = 0; count < numValues; ++count)
        sum += myArray[count];

    sum /= numValues;
    return sum;
}

int main() {
    int intArray[] { 5, 3, 2, 1, 4 };
    std::cout << average(intArray, 5) << '\n';

    double doubleArray[] { 3.12, 3.45, 9.23, 6.34 };
    std::cout << average(doubleArray, 4) << '\n';

    return 0;
}