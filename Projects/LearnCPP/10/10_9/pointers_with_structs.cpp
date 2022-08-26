// https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references/

#include <iostream>

struct Employee {
    int id{};
    int age{};
    double wage{};
};

int main() {
    Employee joe{ 1, 34, 65000.0 };

    ++joe.age;
    joe.wage = 68000.0;

    Employee* ptr{ &joe };
    std::cout << (*ptr).id; // Not great but works: First dereference ptr, then use member selection

    return 0;
}