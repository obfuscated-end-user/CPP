// https://www.learncpp.com/cpp-tutorial/pointers-and-const

int main() {
    int x{ 5 };
    int* const ptr { &x }; // const after the asterisk means this is a const pointer

    return 0;
}