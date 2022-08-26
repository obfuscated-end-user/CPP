// https://www.learncpp.com/cpp-tutorial/pointers-and-const/

int main() {
    const int x{ 5 };
    const int* ptr { &x }; // okay: ptr is pointing to a "const int"

    // *ptr = 6; // not allowed: we can't change a const value

    return 0;
}