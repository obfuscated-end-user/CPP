// https://www.learncpp.com/cpp-tutorial/public-vs-private-access-specifiers/

#include <iostream>

class DateClass {
    int m_month;    // private by default, can only be accessed by other members
    int m_day;  // private by default, can only be accessed by other members
    int m_year; // private by default, can only be accessed by other members

// public interface
public:
    void setDate(int month, int day, int year) {    // public, can be accessed by anyone
        // setDate() can access the priate members of the class because it is a member of the class itself
        m_month = month;
        m_day = day;
        m_year = year;
    }

    void print() {  // public, can be accessed by anyone
        std::cout << m_month << '/' << m_day << '/' << m_year;
    }
};

int main() {
    DateClass date;
    date.setDate(10, 14, 2020); // okay, because setDate() is public
    date.print();   // okay, because print() is public

    return 0;
}