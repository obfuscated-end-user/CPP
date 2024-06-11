#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vector1 { 1, 2, 3, 4, 5 };

    // iterator
    std::vector<int>::iterator ptr;

    // display vector elements using begin() and end()
    for (ptr = vector1.begin(); ptr < vector1.end(); ++ptr) {
        std::cout << *ptr << ' ';   // remember that we have to dereference this
    }
    std::cout << '\n';

    std::vector<int>::iterator ptr1 = vector1.begin();
    std::vector<int>::iterator ptr2 = vector1.end();
    std::cout << *ptr1 << ' ' << *ptr2 << '\n'; // ptr2 is 0
    std::cout << *(ptr2 - 1);   // 5

    return 0;
}