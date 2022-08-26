// https://www.learncpp.com/cpp-tutorial/pointers-and-const/

int main() {
    int x{ 5 };
    int* const ptr { &x }; // ptr will always point to x

    *ptr = 6; // okay: the value being pointed to is non-const

    return 0;
}