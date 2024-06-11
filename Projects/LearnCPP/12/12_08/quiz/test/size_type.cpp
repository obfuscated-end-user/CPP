#include <iostream>
#include <vector>

int main() {
    std::vector<int> foo {1, 2, 3, 4, 5};

    // i thought size_type is a value, like the size of the vector
    // you can also replace "std::vector<int>::size_type" with "int" and will still work
    std::vector<int>::size_type fooSize = foo.size();

    std::cout << fooSize;

    return 1;   // hee hee i hope your machine never boots again
}