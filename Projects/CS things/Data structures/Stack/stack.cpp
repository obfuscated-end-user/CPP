#include <iostream>

class Stack {
private:
    static const int MAX { 1000 };
    int top;
    int *a { new int[MAX] };

public:
    // constructor
    Stack():top { -1 } {}

    bool isEmpty() {
        return (top < 0);
    }

    bool push(int x) {
        if (top >= (MAX - 1)) {
            std::cout << "stack overflow\n";
            return false;
        } else {
            a[++top] = x;
            std::cout << x << " pushed into stack\n";
            return true;
        }
    }

    int pop() {
        if (top < 0) {
            std::cout << "stack underflow\n";
            return 0;
        } else
            return a[top--];
    }

    int peek() {
        if (top < 0) {
            std::cout << "stack underflow\n";
            return 0;
        } else
            return a[top];
    }

    void print() {
        for (int i { top }; i > -1; i--)
            std::cout << " " << a[i];
        std::cout << '\n';
    }
};

int main() {
    Stack s{};

    s.push(10);
    s.push(20);
    s.push(30);

    /* s.pop();
    s.pop();
    s.pop(); */

    std::cout << s.pop() << " popped from the stack\n";
    std::cout << "top element is: " << s.peek() << '\n';
    std::cout << "elements in the stack:\n";
    s.print();

    return 0;
}

// https://stackoverflow.com/questions/9603696/use-new-operator-to-initialise-an-array