// https://www.learncpp.com/cpp-tutorial/null-pointers/

int main() {
    int* ptr {}; // ptr is a null pointer, and is not holding an address
    int* ptr { nullptr }; // can use nullptr to initialize a pointer to be a null pointer

    return 0;
}