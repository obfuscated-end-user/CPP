// https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions

#include <functional>
#include <iostream>

// We don't know what fn will be. std::function works with regular functions and lambdas.
void repeat(int repetitions, const std::function<void(int)>& fn) {  // const auto& fn sends a warning
    for (int i = 0; i < repetitions; ++i)
        fn(i);
}

int main() {
    repeat(3, [](int i) {
        std::cout << i << '\n';
    });

    return 0;
}

// repeat(3, [](int i) { std::cout << i << '\n'; });

// Use auto when initializing variables with lambdas, and std::function if you can’t initialize the variable with the lambda.