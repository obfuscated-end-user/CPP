// https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays

#include <iostream>

int main() {
    const int arr[] { 9, 8, 7, 6, 5 };
    int s { 2 };
    std::cout << arr[s] << '\n';    // okay to use signed index

    unsigned int u { 2 };
    std::cout << arr[u] << '\n';    // okay to use unsigned index

    return 0;
}