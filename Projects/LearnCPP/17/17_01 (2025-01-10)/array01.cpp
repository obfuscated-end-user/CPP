// https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray

#include <array>
#include <vector>

int main() {
    std::array<int, 5> a {};    // a std::array of 5 ints
    std::vector<int> b(5);      // a std::vector of 5 ints (for comparison)

    return 0;
}