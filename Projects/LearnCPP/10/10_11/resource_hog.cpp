// https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides

// define our own pair type
template <typename T, typename U>
struct pair {
    T first{};
    U second{};
};

int main() {
    pair<int, int> p1{ 1, 2 }; // ok: we're explicitly specifying the template arguments
    pair p2{ 1, 2 };           // compile error in C++17

    return 0;
}