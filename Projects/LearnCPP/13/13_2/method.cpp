// https://www.learncpp.com/cpp-tutorial/classes-and-class-members/

#include <iostream>

class DateClass {
public:
    int m_year; // m_ apparently stands for "member"
    int m_month;
    int m_day;

    void print() {
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};

int main() {
    DateClass today {2020, 10, 14};

    today.m_day = 16;   // use member selection operator to select a member of the class
    today.print();  // use member selection to call a member function of the class

    return 0;
}