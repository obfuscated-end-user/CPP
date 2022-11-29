// https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer/

// despite the name, this has nothing to do with matrices. fuck you.
class Simple {
private:
    int m_id;

public:
    Simple(int id) : m_id{ id } {
    }

    void setID(int id) { m_id = id; }
    int getID() { return m_id; }
};

#include <iostream>

int main() {
    Simple simple{1};
    simple.setID(2);
    std::cout << simple.getID() << '\n';

    return 0;
}