// https://www.learncpp.com/cpp-tutorial/arithmetic-conversions/

#include <iostream>
#include <typeinfo> // for typeid()

int main() {
/*     int i{ 2 };
    double d{ 3.5 };
    std::cout << typeid(i + d).name() << ' ' << i + d << '\n'; // show us the type of i + d, shows double

    std::cout << '\n';

    short a{ 4 };
    short b{ 5 };
    std::cout << typeid(a + b).name() << ' ' << a + b << '\n'; // show us the type of a + b, shows integer */

    std::cout << '\n';

    std::cout << typeid(5u-10).name() << ' ' << 5u - 10; // 5u means treat 5 as an unsigned integer, prints out "j 4294967291"

    std::cout << '\n';

    std::cout << std::boolalpha << (-3 < 5u);   // false
    return 0;
}