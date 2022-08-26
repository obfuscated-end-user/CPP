// https://www.learncpp.com/cpp-tutorial/introduction-to-structs-members-and-member-selection/

#include <iostream>

struct Employee {
    int id {};
    int age {};
    double wage {};
};

int main() {
    Employee joe;

    joe.age = 32;  // use member selection operator (.) to select the age member of variable joe
    std::cout << joe.age; // print joe's age

    return 0;
}
