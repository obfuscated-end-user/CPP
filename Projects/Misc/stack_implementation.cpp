// https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials

// TBD
#include <bits/stdc++.h>

#define MAX 1000

class Stack {
    int top;

public:
    int a = MAX;    // maximum size of stack
    // constructor
    Stack() {
        top = -1;
    }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();

};