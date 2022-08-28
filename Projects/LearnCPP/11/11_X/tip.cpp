// https://www.learncpp.com/cpp-tutorial/chapter-11-comprehensive-quiz/

#include <algorithm> // std::shuffle
#include <array>
#include <ctime>
#include <iostream>
#include <numeric> // std::reduce
#include <random>

int main() {
    std::array arr{ 1, 2, 3, 4 };

    std::cout << std::reduce(arr.begin(), arr.end()) << '\n'; // 10

    // If you can't use std::reduce, use std::accumulate. The 0 is the initial value
    // of the result: (((0 + 1) + 2) + 3) + 4
    std::cout << std::accumulate(arr.begin(), arr.end(), 0) << '\n'; // 10

    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(arr.begin(), arr.end(), mt);

    for (int i : arr)
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}