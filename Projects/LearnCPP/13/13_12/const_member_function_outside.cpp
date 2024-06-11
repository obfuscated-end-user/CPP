// https://www.learncpp.com/cpp-tutorial/const-class-objects-and-member-functions

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

    int getValue() const; // note addition of const keyword here
};

int Something::getValue() const {
    return m_value; // and here
}

// also, const functions can't change member variables
// constructors cannot be marked as const