// https://www.learncpp.com/cpp-tutorial/stdvector-capacity-and-stack-behavior/

#include <vector>
#include <iostream>

int main() {
    std::vector<int> array {};
    array = { 0, 1, 2, 3, 4 }; // okay, array length = 5

    std::cout << "length: " << array.size() << " capacity: " << array.capacity() << '\n'; // 5, 5

    array = { 9, 8, 7 };
    std::cout << "length: " << array.size() << " capacity: " << array.capacity() << '\n'; // 3, 5

    return 0;
}