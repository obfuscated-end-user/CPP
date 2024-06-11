// https://www.learncpp.com/cpp-tutorial/recursion

#include <iostream>
#include <vector>

// h/t to potterman28wxcv for a variant of this code
// h/t - "huge thanks" no not really i don't know
int fibonacci(int count) {
    // We'll use a static std::vector to cache calculated results
    static std::vector results {0, 1};

    // If we've already seen this count, then use the cached result
    if (count < static_cast<int>(std::size(results)))
        return results[count];

    // Otherwise calculate the new result and add it
    results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
    return results[count];
}

int main() {
    for (int count = 0; count < 13; ++count)
        std::cout << fibonacci(count) << ' ';

    return 0;
}

// this version only makes 35 function calls, compared to the 1205 calls from the original algorithm