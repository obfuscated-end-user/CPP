// https://www.learncpp.com/cpp-tutorial/pointers-and-const

// A const pointer to a const value can not have its address changed, nor can the value it is pointing
// to be changed through the pointer. It can only be dereferenced to get the value it is pointing at.
int main() {
    int value { 5 };
    const int* const ptr { &value }; // a const pointer to a const value

    return 0;
}