// https://www.learncpp.com/cpp-tutorial/access-functions-and-encapsulation

class Date {
private:
    int m_month;
    int m_day;
    int m_year;

public:
    int getMonth() {    // getter for month
        return m_month;
    }
    void setMonth(int month) {  // setter for month
        m_month = month;
    }

    int getDay() {  // getter for day
        return m_day;
    }
    void setDay(int day) { // setter for day
        m_day = day;
    }

    int getYear() { // getter for year
        return m_year;
    }
    void setYear(int year) {    // setter for year
        m_year = year;
    }
};