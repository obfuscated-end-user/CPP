// https://www.learncpp.com/cpp-tutorial/classes-and-header-files

#include "Date.h"

Date::Date(int year, int month, int day)    // constructor definition
    : m_year { year }
    , m_month { month }
    , m_day { day } {}

void Date::print() const {                  // print function definition
    std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
}