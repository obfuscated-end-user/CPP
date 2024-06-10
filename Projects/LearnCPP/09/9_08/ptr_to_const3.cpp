// https://www.learncpp.com/cpp-tutorial/pointers-and-const

int main() {
    int x{ 5 }; // non-const
    const int* ptr { &x }; // ptr points to a "const int"

    // *ptr = 6;  // not allowed: ptr points to a "const int" so we can't change the value through ptr
    x = 6; // allowed: the value is still non-const when accessed through non-const identifier x

    return 0;
}