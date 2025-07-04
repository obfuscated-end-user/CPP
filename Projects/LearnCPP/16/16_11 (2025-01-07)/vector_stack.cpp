// https://www.learncpp.com/cpp-tutorial/stdvector-and-stack-behavior

#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack) {
	if (stack.empty())	// if stack.size == 0
		std::cout << "Empty";
	
	for (auto element : stack)
		std::cout << element << ' ';
	
	// \t is a tab character, to help align the text
	std::cout << "\tCapacity: " << stack.capacity() << " Length: " << stack.size() << '\n';
}

int main() {
	std::vector<int> stack {};	// empty stack
	// std::vector<int> stack(3);	// parenthesis init to set vector's capacity to 3

	printStack(stack);

	stack.reserve(6);	// reserve space for 6 elements but do not change length
	printStack(stack);

	stack.push_back(1); // push_back() pushes an element on the stack
	printStack(stack);
	
	stack.push_back(2);
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	std::cout << "Top: " << stack.back() << '\n';	// back() returns the last element

	stack.pop_back();	// pop_back() pops an element off the stack
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	return 0;
}