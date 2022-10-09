// https://www.learncpp.com/cpp-tutorial/public-vs-private-access-specifiers/

struct DateStruct { // members are public by default
    int month;  // public by default, can be accessed by anyone
    int day;    // public by default, can be accessed by anyone
    int year;   // public by default, can be accessed by anyone
};

class DateClass {
// public:  // you need this if you want to make these public in a class
    int m_month;    // private by default, can only be accessed by other members
    int m_day;  // private by default, can only be accessed by other members
    int m_year; // private by default, can only be accessed by other members
};

int main() {    // members are private by default
    DateStruct date1;
    date1.month = 10;
    date1.day = 14;
    date1.year = 2020;

    DateClass date2;
    date2.m_month = 10;     // error
    date2.m_day = 14;       // error
    date2.m_year = 2020;    // error

    return 0;
}