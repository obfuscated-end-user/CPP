// https://www.learncpp.com/cpp-tutorial/function-template-specialization

#include <iostream>

template <typename T>
void print(const T& t) {
    std::cout << t << '\n';
}

void print(double d) {
    std::cout << std::scientific << d << '\n';
}

int main() {
    print(5);
    print(6.7);

    return 0;
}