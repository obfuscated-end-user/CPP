// https://www.learncpp.com/cpp-tutorial/introduction-to-iterators

#include <array>    // includes <iterator>
#include <iostream>

int main() {
    std::array array { 1, 2, 3 };

    // Ask our array for the begin and end points (via the begin and end member functions).
    auto begin1 { array.begin() };
    auto end1 { array.end() };

    for (auto p { begin1 }; p != end1; ++p) { // ++ to move to next element.
        std::cout << *p << ' '; // Indirection to get value of current element.
    }
    std::cout << '\n';

    // Use std::begin and std::end to get the begin and end points.
    auto begin2 { std::begin(array) };
    auto end2 { std::end(array) };

    for (auto p { begin2 }; p != end2; ++p) {
        std::cout << *p << ' ';
    }
    std::cout << '\n';
    // for (auto p { end2 }; p != begin2; --p) {

    // This does exactly the same as the loop we used before.
    for (int i : array) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}