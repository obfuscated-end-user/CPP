// https://www.learncpp.com/cpp-tutorial/lambda-captures

#include <iostream>
#include <functional>

// takes in a function as an argument
void myInvoke(const std::function<void()>& fn) {
    fn();
}

int main() {
    int i = 0;

    // Increments and prints its local copy of @i.
    auto count = [i]() mutable {
        std::cout << ++i << '\n';
    };

    myInvoke(count);
    myInvoke(count);
    myInvoke(count);

    return 0;
}