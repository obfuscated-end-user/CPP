// https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator

#include <cassert>  // for assert()
#include <iterator> // for std::size()

class IntList {
private:
    int m_list[10] {};

public:
    int& operator[](int index) {
        return m_list[index];
    }
};

int main() {
    IntList* list { new IntList };
    // list[2] = 3;    // error: this will assume we're accessing index 2 of an array of IntLists
    (*list)[2] = 3; // get our IntList object, then call overloaded operator[]
    delete list;

    return 0;
}