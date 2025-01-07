// https://www.learncpp.com/cpp-tutorial/stdvector-bool

#include <iostream>
#include <vector>

// this works when T is any type but bool
template<typename T>
void foo(std::vector<T>& v) {
    T& first = v[0];    // get a reference to the first element
    // Do something with first
}

int main() {
    std::vector<bool> v { true, false, false, true, true };
    std::vector<int> ints { 1, 2, 3, 4, 5 };

    // foo(v);
    foo(ints);

    for (int i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    // Change the Boolean value with index 4 to false
    v[4] = false;

    for (int i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}

// avoid std::vector<bool>
// https://isocpp.org/blog/2012/11/on-vectorbool