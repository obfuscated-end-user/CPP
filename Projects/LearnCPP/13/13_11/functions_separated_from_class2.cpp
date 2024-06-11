// https://www.learncpp.com/cpp-tutorial/class-code-and-header-files

// refer to chainable_function.cpp in 13_10 directory
class Calc {
private:
    int m_value = 0;

public:
    Calc(int value=0);

    Calc& add(int value);
    Calc& sub(int value);
    Calc& mult(int value);

    int getValue() {
        return m_value;
    }
};

Calc::Calc(int value): m_value{value} {
}

Calc& Calc::add(int value) {
    m_value += value;
    return *this;
}

Calc& Calc::sub(int value) {
    m_value -= value;
    return *this;
}

Calc& Calc::mult(int value) {
    m_value *= value;
    return *this;
}