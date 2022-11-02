// https://www.learncpp.com/cpp-tutorial/public-vs-private-access-specifiers/

/*
Now let’s try something a little more complex. Let’s write a class that implements a simple stack from scratch. Review lesson 12.2 -- The stack and the heap if you need a refresher on what a stack is.

The class should be named Stack, and should contain:

    A private array of integers of length 10.
    A private integer to keep track of the size of the stack.
    A public member function named reset() that sets the size to 0.
    A public member function named push() that pushes a value on the stack. push() should return false if the array is already full, and true otherwise.
    A public member function named pop() that pops a value off the stack and returns it. If there are no values on the stack, the code should exit via an assert.
    A public member function named print() that prints all the values in the stack.

Make sure the following program executes correctly:
int main()
{
	Stack stack;
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
This should print:

( )
( 5 3 8 )
( 5 3 )
( )
*/

// DOES NOT FUCKING WORK DON'T EVEN TRY
#include <iostream>
#include <vector>

class Stack {
    int size = 10;
    int stack[10];
    int counter = 0;
    
public:
    void push(int item) {
        if (counter == size) {
            std::cout << "Stack overflow\n";
        } else {
            stack[counter] = item;
            counter++;
        }
    }

    void pop() {
        if (counter < 0) {
            std::cout << "Stack underflow\n";
        } else {
            int poppedItem = stack[counter];
            counter--;
        }
    }
    void reset() {
        size = 0;
    }

    void print() {
        std::cout << "( ";
        for (int item : stack)
            std::cout << item << ' ';
        std::cout << " )";
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

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}