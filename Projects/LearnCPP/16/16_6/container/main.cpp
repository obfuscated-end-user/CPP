// https://www.learncpp.com/cpp-tutorial/container-classes

#include <iostream>
#include "IntArray.h"

void printArray(IntArray& arr) {
    for (int i = 0; i < arr.getLength(); ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

int main() {
    // make an array with 10 elements
    // 0 0 0 0 0 0 0 0 0 0
    IntArray array(10);
    
    // fill the array with numbers 1-10
    // 1 2 3 4 5 6 7 8 9 10
    for (int i = 0; i < 10; ++i)
        array[i] = i + 1;
    
    // resize the array to 8 elements
    // 1 2 3 4 5 6 7 8
    array.resize(8);
    
    // insert the number 20 before element with index 5
    // 1 2 3 4 5 20 6 7 8
    array.insertBefore(20, 5);

    // remove element with index 3
    // 1 2 3 5 20 6 7 8
    array.remove(3);

    // insert 30 and 40 to the end and beginning
    // 40 1 2 3 5 20 6 7 8 30
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // some random shit
    {
        IntArray b = array;
        b = array;
        b = b;
        array = array;
    }

    printArray(array);

    return 0;
}