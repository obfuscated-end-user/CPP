// https://www.learncpp.com/cpp-tutorial/passing-stdvector

#include <iostream>
#include <vector>

void passByRef(const std::vector<int>& arr) {   // we must explicitly specify <int> here
    std::cout << arr[0] <<'\n';
}

int main() {
    std::vector primes { 2, 3, 5, 7, 11 };
    passByRef(primes);

    return 0;
}