// https://www.learncpp.com/cpp-tutorial/class-code-and-header-files/

// multiple file visual studio code build test
#include "Date.h"
#include <iostream>

// Date constructor
Date::Date(int year, int month, int day) {
    SetDate(year, month, day);
}

// Date member function
void Date::SetDate(int year, int month, int day) {
    m_month = month;
    m_day = day;
    m_year = year;
}

int main() {
    Date date { 1, 2, 3 };
    std::cout << date.getYear() << '/'<< date.getMonth() << '/' << date.getDay();
    std::getchar(); // prevents the window from exiting immediately
    return 0;
}