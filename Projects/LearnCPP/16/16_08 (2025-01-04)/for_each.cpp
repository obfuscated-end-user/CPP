// https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each

#include <iostream>
#include <vector>

int main() {
    std::vector fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    for (int num : fibonacci)       // iterate over array fibonacci and copy each value into `num`
        std::cout << num << ' ';    // print the current value of `num`
    std::cout << '\n';

    std::vector<int> empty { };     // example does not have `<int>`

    for (int num : empty)
        std::cout << "Hi mom!\n";

    for (auto num : fibonacci)
        std::cout << num << ' ';    // compiler will deduce type of numm to be `int`
    std::cout << '\n';

    return 0;
}