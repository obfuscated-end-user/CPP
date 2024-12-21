// https://www.learncpp.com/cpp-tutorial/static-member-variables

#include <utility>  // for std::pair<T, U>

class Foo {
private:
    auto m_x { 5 };             // auto not allowed for non-static members
    std::pair m_v { 1, 2.3 };   // CTAD not allowed for non-static members

    static inline auto s_x { 5 };           // auto allowed for static members
    static inline std::pair s_v { 1, 2.3 }; // CTAD allowed for static members

public:
    Foo() {}
};

int main() {
    Foo foo{};

    return 0;
}