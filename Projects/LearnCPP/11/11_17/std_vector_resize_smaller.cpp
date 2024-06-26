// https://www.learncpp.com/cpp-tutorial/an-introduction-to-stdvector

#include <vector>
#include <iostream>

int main() {
    std::vector array { 0, 1, 2, 3, 4 };
    array.resize(3); // set length to 3

    std::cout << "The length is: " << array.size() << '\n';

    for (int i : array)
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}