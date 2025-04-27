// https://www.learncpp.com/cpp-tutorial/c-style-array-decay

#include <iostream>

// function is type int on the website
void printArrayLength(int arr[]) {
    std::cout << std::size(arr) << '\n';    // compile error: std::size() won't work on a pointer
}

int main() {
    int arr[] { 3, 2, 1 };

    std::cout << std::size(arr) << '\n';    // prints 3
    printArrayLength(arr);

    return 0;
}