// https://www.learncpp.com/cpp-tutorial/stdvector-capacity-and-stack-behavior/

#include <vector>
#include <iostream>

int main() {
    std::vector<int> array {0, 1, 2};
    array.resize(5); // set length to 5

    std::cout << "The length is: " << array.size() << '\n';

    for (auto element : array)
        std::cout << element << ' ';

    return 0;
}