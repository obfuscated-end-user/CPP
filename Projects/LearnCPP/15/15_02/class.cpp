// https://www.learncpp.com/cpp-tutorial/classes-and-header-files

#include <iostream>

class Date {
private:
    int m_year {};
    int m_month {};
    int m_day {};

public:
    Date(int year, int month, int day); // constructor declaration

    void print() const;                 // print function declaration

    int getYear() const {
        return m_year;
    }

    int getMonth() const {
        return m_month;
    }

    int getDay() const {
        return m_day;
    }
};

Date::Date(int year, int month, int day)    // constructor definition
    : m_year { year }
    , m_month { month }
    , m_day { day } {}

void Date::print() const {
    std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
}

int main() {
    const Date d  { 2015, 10, 14 };
    d.print();

    return 0;
}