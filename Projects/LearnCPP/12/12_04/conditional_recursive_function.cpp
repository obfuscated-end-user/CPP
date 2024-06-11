// https://www.learncpp.com/cpp-tutorial/recursion

#include <iostream>

void countDown(int count) {
    std::cout << "push " << count << '\n';

    // if count is greater than 1, do something. else, stop.
    if (count > 1) {    // termination condition
        countDown(count - 1);
    }

    // this will also run 5 times, don't get confused, because remember, this is still in the function
    std::cout << "pop " <<  count << '\n';
}

int main() {
    countDown(5);

    return 0;
}

// It’s worth noting that the “push” outputs happen in forward order since they occur before the recursive function call. The “pop” outputs occur in reverse order because they occur after the recursive function call, as the functions are being popped off the stack (which happens in the reverse order that they were put on).