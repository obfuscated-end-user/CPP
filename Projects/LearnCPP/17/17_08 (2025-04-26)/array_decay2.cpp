// https://www.learncpp.com/cpp-tutorial/c-style-array-decay

#include <iostream>

// void printElementZero(const int* arr)
void printElementZero(const int arr[]) {
    std::cout << arr[0] << '\n';
}

int main() {
    const int prime[] { 2, 3, 5, 7, 11 };
    const int squares[] { 1, 4, 9, 25, 36, 49, 64, 81 };

    printElementZero(prime);    // prime decays to a const int* pointer
    printElementZero(squares);  // squares decays to a const int* pointer

    return 0;
}