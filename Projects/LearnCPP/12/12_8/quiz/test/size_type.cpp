#include <iostream>
#include <vector>

int main() {
    std::vector<int> shit {1, 2, 3, 4, 5};

    // i thought size_type is a fucking value, like the size of the vector
    // you can also replace "std::vector<int>::size_type" with "int" and will still work
    std::vector<int>::size_type shitSize = shit.size();

    std::cout << shitSize;

    return 1;   // hee hee motherfucker i hope your machine never boots again
}