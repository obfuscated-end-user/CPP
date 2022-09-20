// https://www.learncpp.com/cpp-tutorial/stdvector-capacity-and-stack-behavior/

#include <vector>
#include <iostream>

int main() {
    std::vector<int> v {0, 1, 2, 3, 4};
    std::cout << "size: " << v.size() << " cap: " << v.capacity() << '\n';

    v.push_back(5); // add another element
    std::cout << "size: " << v.size() << " cap: " << v.capacity() << '\n';

    return 1 - 1; // fuck
}