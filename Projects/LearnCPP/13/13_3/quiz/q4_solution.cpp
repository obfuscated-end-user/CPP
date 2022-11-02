// https://www.learncpp.com/cpp-tutorial/public-vs-private-access-specifiers/

#include <array>
#include <cassert>
#include <iostream>

class Stack {
private:
    // We use a std::array to store the elements
    using Array = std::array<int, 10>;
    // For conveience, add a type alias for the type of the indexes
    using Index = Array::size_type;

    Array m_array {};   // Here's where we're goind to store our stack data
    Index m_next = 0;   // This will hold the index of the next free element of the stack

public:
    void reset() {
        m_next = 0;
    }

    bool push(int value) {
        // If the stack is already full, return false now
        if (m_next == m_array.size())
            return false;
        
        m_array[m_next++] = value;  // set the next free element to the value, then increase m_next
        return true;
    }

    int pop() {
        // If there are no elements on the stack, assert out
        assert(m_next > 0 && "Can not pop empty stack");
        // m_next points to the next free element, so the last valid element is m_next -1.
        // what we want to do is something like this:
        // int val = m_array[m_next-1]; // get the last valid element
        // --m_next; // m_next is now one less since we just removed the top element
        // return val; // return the element
        // that can be condensed into this:
        return m_array[--m_next];
    }

    void print() {
        std::cout << "( ";
        for (Index i = 0; i < m_next; ++i)
            std::cout << m_array[i] << ' ';
        std::cout << ")\n";
    }
};

int main() {
    Stack stack;
    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.reset();
    stack.print();
}

/*
// alt answer using the built in stack and vector libraries
#include <iostream>
#include <vector>

// std::stack only provides access to the topmost element. If we want to
// print all elements, we need to copy the stack (by passing it by value)
// and pop elements until the stack is empty.
void printStack(std::vector<int> stack)
{
	std::cout << "( ";
	for (auto e : stack)
		std::cout << e << ' ';
	std::cout << ")\n";
}

int main()
{
	// Create a std::stack that holds ints.
	std::vector<int> stack;

	printStack(stack);

	stack.push_back(5);
	stack.push_back(3);
	stack.push_back(8);
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	// To clear the stack, assign it an empty vector.
	stack = {};
	printStack(stack);

	return 0;
}
*/