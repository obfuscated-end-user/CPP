// https://www.learncpp.com/cpp-tutorial/c-style-array-decay

#include <cassert>
#include <iostream>

void printElement2(const int arr[], int length) {
    assert(length > 2 && "printElement2: Array too short"); // can't static_assert on length

    std::cout << arr[2] << '\n';
}

int main() {
    constexpr int a[] { 3, 2, 1 };
    printElement2(a, static_cast<int>(std::size(a)));   // ok

    constexpr int b[] { 7, 6 };
    printElement2(b, static_cast<int>(std::size(b)));   // will trigger assert

    return 0;
}