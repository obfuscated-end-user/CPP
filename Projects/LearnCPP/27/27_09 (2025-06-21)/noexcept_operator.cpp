// https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept

void foo() {
    throw -1;
}

void boo() {};
void goo() noexcept {};
struct S {};

int main() {
    constexpr bool b1 { noexcept(5 + 3) };  // true; ints are non-throwing
    constexpr bool b2 { noexcept(foo()) };  // false; foo() throws an exception
    constexpr bool b3 { noexcept(boo()) };  // false; boo() is implicitly noexcept(false)
    constexpr bool b4 { noexcept(goo()) };  // true; goo() is explicitly noexcept(true)
    constexpr bool b5 { noexcept(S {}) };   // true; a struct's default constructor is noexcept by default

    return 0;
}