// https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios

#include <iostream>

int main() {
    std::cout << true << ' ' << false << '\n';

    std::cout.setf(std::ios::boolalpha);
    std::cout << true << ' ' << false << '\n';

    std::cout << std::noboolalpha << true << ' ' << false << '\n';

    std::cout << std::boolalpha << true << ' ' << false << '\n';

    return 0;
}