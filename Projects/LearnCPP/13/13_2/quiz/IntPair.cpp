// https://www.learncpp.com/cpp-tutorial/classes-and-class-members/

/*
Question #1

a) Create a class called IntPair that holds two integers. This class should have two member variables to hold the integers. You should also create two member functions: one named “set” that will let you assign values to the integers, and one named “print” that will print the values of the variables.

The following main function should execute:

int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	return 0;
}

and produce the output:

Pair(1, 1)
Pair(2, 2)
*/

#include <iostream>

class IntPair {
public:
    int m_num1;
    int m_num2;

    void set(int num1, int num2) {
        m_num1 = num1;
        m_num2 = num2;
    }

    void print() {
        std::cout << "Pair(" << m_num1 << ", " << m_num2 << ")\n";
    }
};

int main() {
    IntPair p1;
    p1.set(1, 1);   // set p1 values to (1, 1)

    IntPair p2 { 2, 2 };    // initialize p2 values to (2, 2)

    p1.print();
    p2.print();

    return 0;
}