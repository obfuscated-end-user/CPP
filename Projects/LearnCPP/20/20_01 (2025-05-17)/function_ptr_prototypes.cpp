// https://www.learncpp.com/cpp-tutorial/function-pointers

// function prototypes
int foo();
double goo();
int hoo(int x);

int main() {
    // function pointer initializers
    int (*fcnPtr1)() { &foo };      // okay
    int (*fcnPtr2)() { &goo };      // wrong -- return types don't match!
    double (*fcnPtr4)() { &goo };   // okay
    fcnPtr1 = &hoo;                 // wrong -- fcnPtr1 has no parameters, but hoo() does
    int (*fcnPtr3)(int) { &hoo };   // okay

    // function initializations
    int (*fcnPtr5)() { foo };   // okay, foo implicitly converts to function pointer to foo
    void* vPtr { foo };         // not okay, though some compilers may allow

    int (*fcnptr)() { nullptr };

    return 0;
}