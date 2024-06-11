// https://www.learncpp.com/cpp-tutorial/the-stack-and-the-heap

int foo(int x) {
    // b
    return x;
} // foo is popped off the call stack here

int main() {
    // a
    foo(5); // foo is pushed on the call stack here
    // c

    return 0;
}

/*
The call stack looks like the following at the labeled points:
a:
main()
b:
foo() (including parameter x)
main()
c:
main()
*/