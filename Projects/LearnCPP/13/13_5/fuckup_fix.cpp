// https://www.learncpp.com/cpp-tutorial/constructors/

class Date {
private:
    int m_year{ 1900 };
    int m_month{ 1 };
    int m_day{ 1 };

public:
    // Tell the compiler to create a default constructor, even if
    // there are other user-provided constructors.
    Date() = default;

    Date(int year, int month, int day) { // normal non-default constructor
        m_year = year;
        m_month = month;
        m_day = day;
    }
};

int main() {
    Date date{}; // date is initialized to Jan 1st, 1900
    Date today{ 2020, 10, 14 }; // today is initialized to Oct 14th, 2020

    return 0;
}