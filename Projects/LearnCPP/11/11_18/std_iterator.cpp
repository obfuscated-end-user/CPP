// https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/

#include <array>
#include <iostream>

int main() {
    std::array array{ 1, 2, 3 };

    // Ask our array for the begin and end points (via the begin and end member functions).
    // THESE ARE POINTERS
    auto begin{ array.begin() };
    auto end{ array.end() };

    for (auto p{ begin }; p != end; ++p) { // ++ to move to next element.
        std::cout << *p << ' '; // Indirection to get value of current element.
    }
    std::cout << '\n';

    return 0;
}

// ++p means increment p pointer to whatever type it points to. since p is a int pointer, it increments 4 instead of just 1
// fuck you

/*
Don’t worry about the types of the iterators for now, we’ll re-visit iterators in a later chapter. The important thing is that the iterator takes care of the details of iterating through the container. All we need are four things: the begin point, the end point, operator++ to move the iterator to the next element (or the end), and operator* to get the value of the current element.
*/