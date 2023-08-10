// https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator

#include <iostream>

class IntList {
private:
    int m_list[10];

public:
    int& operator[] (int index);
};

int& IntList::operator[] (int index) {
    return m_list[index];
}

int main(int argc, char const *argv[]) {
    IntList list{};
    list[2] = 3; // set a value
    std::cout << list[2] << '\n'; // get a value

    return 0;
}