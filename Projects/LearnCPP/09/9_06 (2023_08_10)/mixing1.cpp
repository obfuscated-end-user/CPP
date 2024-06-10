// https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference

#include <string>

void foo(int a, int& b, const std::string& c) {}

int main() {
    int x = 5;
    const std::string s = "Hello, world!";

    foo(5, x, s);

    return 0;
}