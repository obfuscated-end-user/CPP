// https://www.learncpp.com/cpp-tutorial/function-pointers

int foo(int x) {
    return x;
}

// implicit dereference
int main() {
    int (*fcnPtr)(int){ &foo }; // Initialize fcnPtr with function foo
    fcnPtr(5); // call function foo(5) through fcnPtr.

    return 0;
}