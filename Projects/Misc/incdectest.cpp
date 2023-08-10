#include <iostream>

int main() {
    int a = 5;
    std::cout << a << '\n';    // 5
    std::cout << ++a << '\n';  // 6
    std::cout << a << '\n';    // 6

    int b = 5;
    std::cout << b << '\n';    // 5
    std::cout << b++ << '\n';  // 5
    std::cout << b << '\n';    // 6
    return 0;
}