// https://www.learncpp.com/cpp-tutorial/pointers-and-const

int main() {
    const int x{ 5 };
    const int* ptr { &x }; // ptr points to const int x

    const int y{ 6 };
    ptr = &y; // okay: ptr now points at const int y

    return 0;
}