// https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray

/*
Complete the following program:
#include <array>
#include <iostream>
int main()
{
constexpr std::array arr1 { 1, 4, 9, 16 };
printArray(arr1);
constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
printArray(arr2);
return 0;
}
When run, it should print:
The array (1, 4, 9, 16) has length 4
The array (h, e, l, l, o) has length 5
*/

#include <array>
#include <iostream>

template <typename T, std::size_t N>
void printArray(const std::array<T, N>& arr) {
    std::cout << "The array (";

    auto separator { "" };
    for (const auto& e : arr) {
        std::cout << separator << e;
        separator = ", ";
    }

    std::cout << ") has length " << N << '\n';
}

int main() {
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}