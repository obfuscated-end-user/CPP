// https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/

template <typename T, typename U>
struct pair {
    T first{};
    U second{};
};

// Here's a deduction guide for our pair class
// pair objects initialized with arguments of type T and U should deduce to pair<T, U>
template <typename T, typename U>
pair(T, U) -> pair<T, U>;

int main() {
    pair<int, int> p1{ 1, 2 }; // explicitly specify class template pair<int, int> (C++11 onward)
    pair p2{ 1, 2 };     // CTAD used to deduce pair<int, int> from the initializers (C++17)

    return 0;
}