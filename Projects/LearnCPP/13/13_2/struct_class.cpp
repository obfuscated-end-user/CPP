// https://www.learncpp.com/cpp-tutorial/classes-and-class-members/

struct DateStruct {
    int year;
    int month;
    int day;
};

class DateClass {
public:
    int m_year;
    int m_month;
    int m_day;
};

DateClass today { 2020, 10, 14 }; // declare a variable of class DateClass

// look at that where the fuck did main() go