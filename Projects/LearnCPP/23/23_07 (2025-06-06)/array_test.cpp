// https://www.learncpp.com/cpp-tutorial/stdinitializer_list

#include <iostream>

int main() {
    int array1[] { 5, 4, 3, 2, 1 }; // initializer list
    for (auto i : array1)
        std::cout << i << ' ';

    std::cout << '\n';

    auto* array2 { new int[5]{ 5, 4, 3, 2, 1 } };
    for (int count { 0 }; count < 5; ++count)
        std::cout << array2[count] << ' ';
    delete[] array2;

    return 0;
}