// https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/

#include <utility> // for std::pair

int main() {
    std::pair<> p1 { 1, 2 };    // error: too few template arguments, both arguments not deduced
    std::pair<int> p2 { 3, 4 }; // error: too few template arguments, second argument not deduced

    return 0;
}