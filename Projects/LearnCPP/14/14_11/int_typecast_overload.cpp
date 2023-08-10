// https://www.learncpp.com/cpp-tutorial/overloading-typecasts

#include <iostream>

class Cents {
private:
    int m_cents;
public:
    Cents(int cents=0): m_cents{cents} {}

    // Overloaded int cast
    operator int() const { return m_cents; }

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }

};

void printInt(int integer) {
    std::cout << integer;
}

int main() {
    Cents cents{ 7 };
    int c = static_cast<int>(cents);
    printInt(c); // print 7
    std::cout << '\n';

    return 0;
}

/*
1. To overload the function that casts our class to an int, we write a new function in our class called operator int(). Note that there is a space between the word operator and the type we are casting to. Such functions must be non-static members.
2. User-defined conversions do not have parameters, as there is no way to pass arguments explicitly to them. They do still have a hidden *this parameter, pointing to the implicit object (which is the object to be converted)
3. User-defined conversions do not declare a return type. The name of the conversion (e.g. int) is used as the return type, as it is the only return type allowed. This prevents redundancy.
*/