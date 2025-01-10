// https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray

#include <array>
#include <vector>

int main() {
    std::array<int, 6> fibonacci = { 0, 1, 1, 2, 3, 5 };    // copy-list initialization using braced list
    std::array<int, 5> prime { 2, 3, 5, 7, 11 };            // list initialization using braced list (preferred)

    std::array<int, 5> a;       // Members default intialized (int elements are left uninitialized)
    std::array<int, 5> b {};    // Members value intialized (int elements are zero initialized) (preferred)
    std::vector<int> v(5);      // Members value intialized (int elements are zero initialized) (for comparison)

    // std::array<int, 4> c { 1, 2, 3, 4, 5 }; // compile error: too many initializers
    std::array<int, 4> d { 1, 2 };          // b[2] and b[3] are value initialized

    return 0;
}