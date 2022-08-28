// https://www.learncpp.com/cpp-tutorial/an-introduction-to-stdvector/

#include <iostream>
#include <vector>

int main() {
    std::vector array { 0, 1, 2 };
    array.resize(5); // set size to 5

    std::cout << "The length is: " << array.size() << '\n';

    for (int i : array)
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}