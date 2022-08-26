// https://www.learncpp.com/cpp-tutorial/pointers-and-const/

int main() {
    int x{ 5 };
    int y{ 6 };

    int* const ptr { &x }; // okay: the const pointer is initialized to the address of x
    // ptr = &y; // error: once initialized, a const pointer can not be changed.

    return 0;
}