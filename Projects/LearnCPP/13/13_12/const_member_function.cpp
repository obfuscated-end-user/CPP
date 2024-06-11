// https://www.learncpp.com/cpp-tutorial/const-class-objects-and-member-functions

/*
A const member function is a member function that guarantees it will not modify the object or call any non-const member functions (as they may modify the object).

To make getValue() a const member function, we simply append the const keyword to the function prototype, after the parameter list, but before the function body:
*/

class Something {
public:
    int m_value {};

    Something(): m_value{0} { }

    void resetValue() {
        m_value = 0;
    }
    void setValue(int value) {
        m_value = value;
    }

    int getValue() const {
        return m_value;
    } // note addition of const keyword after parameter list, but before function body
};