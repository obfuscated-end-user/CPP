// https://www.learncpp.com/cpp-tutorial/overloading-the-increment-and-decrement-operators

#include <iostream>

class Digit {
private:
    int m_digit;
public:
    Digit(int digit=0): m_digit{digit} {}

    Digit& operator++(); // prefix has no parameter
    Digit& operator--(); // prefix has no parameter

    Digit operator++(int); // postfix has an int parameter
    Digit operator--(int); // postfix has an int parameter

    friend std::ostream& operator<< (std::ostream& out, const Digit& d);
};

// No parameter means this is prefix operator++
Digit& Digit::operator++() {
    if (m_digit == 9)
        m_digit = 0;
    else
        ++m_digit;

    return *this;
}

// No parameter means this is prefix operator--
Digit& Digit::operator--() {
    if (m_digit == 0)
        m_digit = 9;
    else
        --m_digit;

    return *this;
}

// int parameter means this is postfix operator++
// "Because the dummy parameter is not used in the function implementation, we have not even given it a name. This tells the compiler to treat this variable as a placeholder, which means it won’t warn us that we declared a variable but never used it." - the int parameter
Digit Digit::operator++(int) {
    // Create a temporary variable with our current digit
    Digit temp{*this};

    // Use prefix operator to increment this digit
    ++(*this); // apply operator

    // return temporary result
    return temp; // return saved state
}

// int parameter means this is postfix operator--
Digit Digit::operator--(int) {
    Digit temp{*this};

    // Use prefix operator to decrement this digit
    --(*this);

    return temp;
}

std::ostream& operator<< (std::ostream& out, const Digit& d) {
	out << d.m_digit;
	return out;
}

int main() {
    Digit digit(5);

    std::cout << digit;
    std::cout << ++digit; // calls Digit::operator++();
    std::cout << digit++; // calls Digit::operator++(int);
    std::cout << digit;
    std::cout << --digit; // calls Digit::operator--();
    std::cout << digit--; // calls Digit::operator--(int);
    std::cout << digit;

    return 0;
}

/*
fuck

prefix:
- no params
- return *this;
- returns the object after it has been in/decremented

postfix:
- has "int" as a parameter (yes, just "int")
- does the weird return temp shit
- needs to return the state of the object before it is in/decremented
*/