// https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors

#include <vector>

int main() {
    // Value initialization (uses default constructor)
    std::vector<int> empty {};  // vector containing 0 int elements

    // List construction (uses list constructor)
    std::vector<int> primes { 2, 3, 5, 7 };         // vector containing 4 int elements with values 2, 3, 5, 7
    std::vector vowels { 'a', 'e', 'i', 'o', 'u' }; // vector containing 5 char elements with values 'a', 'e', 'i', 'o', 'u'. Uses CTAD (C++17) to deduce element type char (preferred).

    return 0;
}