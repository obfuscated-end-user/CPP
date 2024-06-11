// https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists

class Something {
private:
    int m_value1 {};
    double m_value2 {};
    char m_value3 {};

public:
    Something() {
        // These are all assignments, not initializations
        m_value1 = 1;
        m_value2 = 2.2;
        m_value3 = 'c';
    }
};