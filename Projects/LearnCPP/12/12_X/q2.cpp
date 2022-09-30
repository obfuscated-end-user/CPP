// https://www.learncpp.com/cpp-tutorial/chapter-12-comprehensive-quiz/

/*
Question #2

What’s wrong with these programs?
*/

// a)
int& doSomething() {
    int array[]{ 1, 2, 3, 4, 5 };
    return array[3];
}
// you: returns an int instead of an int reference
// answer: doSomething() returns a reference to a local variable that will be destroyed when doSomething terminates.

// b)
int sumTo(int value) {
    return value + sumTo(value - 1);
}
// you: no base case, causing an infinite loop
// answer: function sumTo () has no termination condition. Variable value will eventually go negative, and the function will loop infinitely until the stack overflows.

// c)
float divide(float x, float y) {
    return x / y;
}

double divide(float x, float y) {
    return x / y;
}
// you: float is also double i don't fucking know
// answer: The two divide functions are not distinct, as they have the same name and same parameters. There is also a potential divide by 0 issue.

// d)
#include <iostream>

int main() {
    int array[100000000]{};

    for (auto x: array)
        std::cout << x << ' ';

    std::cout << '\n';

    return 0;
}
// you: stack overflow
// answer: The array is too large to be allocated on the stack. It should be dynamically allocated.

// e)
#include <iostream>

int main(int argc, char* argv[]) {
    int age{ argv[1] };
    std::cout << "The user's age is " << age << '\n';

    return 0;
}
// you: assigning a char to an int doesn't work
// answer: argv[1] may not exist. If it does, argv[1] is a string argument, and can’t be converted to an integer via assignment.