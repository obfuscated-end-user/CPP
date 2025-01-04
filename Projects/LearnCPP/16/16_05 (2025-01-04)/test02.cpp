// https://www.learncpp.com/cpp-tutorial/returning-stdvector-and-an-introduction-to-move-semantics

#include <iostream>
#include <vector>

std::vector<int> doSomething(std::vector<int> v2) {
    std::vector v3 { v2[0] + v2[0] };   // 3 -- construct value to be returned to caller
    return v3;  // 4 -- actually retun value
}

int main() {
    std::vector v1 { 5 };   // 1 -- construct value to be passed to function
    std::cout << doSomething(v1)[0] << '\n';    // 2 -- actually pass value

    std::cout << v1[0] << '\n';

    return 0;
}