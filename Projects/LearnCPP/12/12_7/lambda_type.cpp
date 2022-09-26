// https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/

#include <functional>

int main() {
    // A regular function pointer. Only works with an empty capture clause (empty []).
    double (*addNumbers1)(double, double) {
        [](double a, double b){
            return a + b;
        }
    };

    addNumbers1(1, 2);

    // Using std::function. The lambda could have a non-empty capture clause (discussed next lesson.)
    std::function addNumbers2 {
        [](double a, double b) {
            return (a + b);
        }
    };

    addNumbers2(3, 4);

    // Using auto. Stores the lambda with its real type.
    auto addNumbers3 {
        [](double a, double b) {    // note: pre-C++17, use std::function<double(double, double)> instead
            return (a + b);
        }
    };

    addNumbers3(5, 6);

    return 0;
}