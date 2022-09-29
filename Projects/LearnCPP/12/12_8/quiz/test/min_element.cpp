#include <algorithm>
#include <iostream>
#include <vector>

bool compare(int a, int b) {
    return a < b;   // this also has to be operator<, any other comparison operator will fuck your code up
}

int main() {
    std::vector<int> vector1 {1, 2, 3, 4, 5};
    // using a lambda
    // you still have to dereference this because this is a pointer
    int min1 = *std::min_element(vector1.begin(), vector1.end(), [](int a, int b){return a < b;});
    std::cout << min1 << '\n';

    std::vector<int> vector2 {32, 35, 31, 44, 55};
    // same thing but with a function instead of a lambda
    int min2 = *std::min_element(vector2.begin(), vector2.end(), compare);
    std::cout << min2 << '\n';

    return 0;
}