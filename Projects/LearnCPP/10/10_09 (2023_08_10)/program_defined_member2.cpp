// https://www.learncpp.com/cpp-tutorial/struct-miscellany

#include <iostream>

struct Company {
    struct Employee {   // accessed via Company::Employee
        int id;
        int age;
        double wage;
    };

    int numberOfEmployees;
    Employee CEO; // Employee is a struct within the Company struct
};

int main() {
    Company myCompany{ 7, { 1, 32, 55000.0 } };
    std::cout << myCompany.CEO.wage << '\n'; // print the CEO's wage

    return 0;
}