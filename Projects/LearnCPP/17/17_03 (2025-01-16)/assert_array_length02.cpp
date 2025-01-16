// https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray

#include <array>
#include <iostream>

template <typename T, std::size_t N>
void printElement3(const std::array<T, N>& arr) {
    // precondition: array length must be greater than 3 so element 3 exists
    static_assert(N > 3);

    // we can assume the array length is greater than 3 beyond this point
    std::cout << arr[3] << '\n';
}

int main() {
    std::array arr { 9, 7, 5, 3, 1 };
    printElement3(arr);     // okay

    std::array arr2 { 9, 7 };
    printElement3(arr2);    // compile error

    return 0;
}