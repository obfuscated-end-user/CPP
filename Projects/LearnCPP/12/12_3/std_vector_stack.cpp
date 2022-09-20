// https://www.learncpp.com/cpp-tutorial/stdvector-capacity-and-stack-behavior/

#include <vector>
#include <iostream>

void printStack(const std::vector<int>& stack) {
    for (auto element : stack)
        std::cout << element << ' ';
    std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}

int main() {
    std::vector<int> stack{};
    
    // Because resizing the vector is expensive, we can tell the vector to allocate a certain amount of capacity up front using the reserve() function:
    stack.reserve(5); // Set the capacity to (at least) 5
    // remove this and the cap will be 4 (at least on my machine)

    printStack(stack);

    stack.push_back(5); // push_back pushes an element on the stack
    printStack(stack);

    stack.push_back(3);
    printStack(stack);

    stack.push_back(2);
    printStack(stack);

    std::cout << "top: " << stack.back() << '\n'; // back() returns the last element

    stack.pop_back(); // pop_back() pops an element off the stack
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    return 0;
}