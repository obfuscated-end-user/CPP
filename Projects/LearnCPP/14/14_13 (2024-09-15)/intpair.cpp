// https://www.learncpp.com/cpp-tutorial/temporary-class-objects

#include <iostream>

class IntPair {
private:
    int m_x {};
    int m_y {};

public:
    IntPair(int x, int y) : m_x { x }, m_y { y } {}

    int x() const {
        return m_x;
    }

    int y() const {
        return m_y;
    }
};

void print(IntPair p) {
    std::cout << '(' << p.x() << ", " << p.y() << ")\n";
}

// Case 1: Create named variable and return
IntPair ret1() {
    IntPair p { 3, 4 };
    return p;
}

// Case 2: Create temporary IntPair and return
IntPair ret2() {
    return IntPair { 5, 6 };
}

// Case 3: implicitly convert { 7, 8 } to IntPair and return
IntPair ret3() {
    return { 7, 8 };
}

int main() {
    print(ret1());
    print(ret2());
    print(ret3());

    return 0;
}