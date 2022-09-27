// https://www.learncpp.com/cpp-tutorial/lambda-captures/

#include <iostream>
#include <functional>

void myInvoke(const std::function<void()>& fn) {
    fn();
}

int main() {
    int i = 0;

    // Increments and prints its local copy of @i.
    auto count = [i]() mutable {
        std::cout << ++i << '\n';
    };

    // std::ref(count) ensures count is treated like a reference
    // thus, anything that tries to copy count will actually copy the reference
    // ensuring that only one count exists
    myInvoke(std::ref(count));
    myInvoke(std::ref(count));
    myInvoke(std::ref(count));

    return 0;
}

/*
Try to avoid mutable lambdas. Non-mutable lambdas are easier to understand and don’t suffer from the above issues, as well as more dangerous issues that arise when you add parallel execution.
*/