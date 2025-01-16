// https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray

#include <array>
#include <iostream>

template <typename T, std::size_t N>
void printElement3(const std::array<T, N>& arr) {
    // std::cout << arr[3] << '\n';
    std::cout << std::get<3>(arr) << '\n';  // checks that index 3 is valid at compile-time
}

int main() {
    std::array arr1 { 9, 7, 5, 3, 1 };
    printElement3(arr1);    // okay

    std::array arr2 { 9, 7 };
    printElement3(arr2);    // compile error

    return 0;
}