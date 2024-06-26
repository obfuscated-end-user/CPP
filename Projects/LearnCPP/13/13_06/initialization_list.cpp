// https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists

#include <iostream>

class Something {
private:
    int m_value1 {};
    double m_value2 {};
    char m_value3 {};

public:
    // Initialize our member variables
    Something() : m_value1{ 1 }, m_value2{ 2.2 }, m_value3{ 'c' } {
    // No need for assignment here
    }

    void print() {
        std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }
};

int main() {
    Something something{};
    something.print();
    return 0;
}