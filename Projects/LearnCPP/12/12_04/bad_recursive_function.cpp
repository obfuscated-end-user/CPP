// https://www.learncpp.com/cpp-tutorial/recursion

#include <iostream>

void countDown(int count) {
    std::cout << "push " << count << '\n';
    countDown(count - 1);   // countDown calls itselt recursively
}

int main() {
    countDown(5);   // infinite loop

    return 0;
}

// this will run until the call stack runs out of memory
// mine stopped at -43146