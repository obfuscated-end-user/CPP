// https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors

#include <vector>

struct Foo {
    // std::vector<int> v1(8); // compile error: direct initialization not allowed for member default
    std::vector<int> v { std::vector<int>(8) }; // ok
};

int main() {
    return 0;
}