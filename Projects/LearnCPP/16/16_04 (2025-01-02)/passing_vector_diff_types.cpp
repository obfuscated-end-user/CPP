// https://www.learncpp.com/cpp-tutorial/passing-stdvector

#include <iostream>
#include <vector>

template <typename T>
void passByRef(const std::vector<T>& arr) {
    std::cout << arr[0] << '\n';
}

int main() {
    std::vector primes { 2, 3, 5, 7, 11 };
    passByRef(primes);  // ok: compiler will instantiate passByRef(const std::vector<int>&)
    
    std::vector dbl { 1.1, 2.2, 3.3 };
    passByRef(dbl);  // ok: compiler will instantiate passByRef(const std::vector<double>&)
    return 0;
}