// https://www.learncpp.com/cpp-tutorial/class-code-and-header-files

/*
You learned that you can put function declarations inside header files in order to use those functions in multiple files or even multiple projects. Classes are no different. Class definitions can be put in header files in order to facilitate reuse in multiple files or multiple projects. Traditionally, the class definition is put in a header file of the same name as the class, and the member functions defined outside of the class are put in a .cpp file of the same name as the class.
*/

#ifndef DATE_H
#define DATE_H

class Date {
private:
    int m_year;
    int m_month;
    int m_day;

public:
    Date(int year, int month, int day);

    void SetDate(int year, int month, int day);

    int getYear() {
        return m_year;
    }

    int getMonth() {
        return m_month;
    }

    int getDay() {
        return m_day;
    }
};

#endif