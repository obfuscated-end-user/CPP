// https://www.learncpp.com/cpp-tutorial/chapter-21-summary-and-quiz

/*
Overload operator==, operator>>, operator- (unary), and operator+ (binary).

The following program should run:

```
#include <cassert>
#include <iostream>

int main()
{
	assert(FixedPoint2{ 0.75 } == FixedPoint2{ 0.75 });    // Test equality true
	assert(!(FixedPoint2{ 0.75 } == FixedPoint2{ 0.76 })); // Test equality false

	// Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 });    // both positive, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 });    // both positive, with decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }); // both negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }); // both negative, with decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 });  // second negative, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 });  // second negative, possible decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 });   // first negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 });   // first negative, possible decimal overflow

	FixedPoint2 a{ -0.48 };
	assert(static_cast<double>(a) == -0.48);
	assert(static_cast<double>(-a) == 0.48);

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	assert(static_cast<double>(a) == 5.68);

	return 0;
}
```

Hint: Add your two FixedPoint2 together by leveraging the double cast, adding the results, and converting back to a FixedPoint2. This elegantly handles overflowing decimals.

Hint: For operator>>, use your double constructor to create an anonymous object of type FixedPoint2, and assign it to your FixedPoint2 function parameter.
*/


#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>

class FixedPoint2 {
private:
    std::int16_t m_base {};
    std::int8_t m_decimal {};

public:
    FixedPoint2(std::int16_t base=0, std::int8_t decimal=0)
        : m_base { base }, m_decimal { decimal } {
        if (m_base < 0 || m_decimal < 0) {
            if (m_base > 0)
                m_base = -m_base;
            if (m_decimal > 0)
                m_decimal = -m_decimal;
        }

		m_base += m_decimal / 100;
		m_decimal = m_decimal % 100;
    }

	// We'll delegate to the prior constructor so we don't have to duplicate the negative number and overflow handling logic
	FixedPoint2(double d) : 
		FixedPoint2(
			static_cast<std::int16_t>(std::trunc(d)),
			static_cast<std::int8_t>(std::round(d * 100) - std::trunc(d) * 100)
		) {}

    explicit operator double() const {
        return m_base + (static_cast<double>(m_decimal) / 100);
    }

	friend bool operator==(const FixedPoint2& fp1, const FixedPoint2& fp2) {
		return fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal;
	}

	FixedPoint2 operator-() const {
		// Cast to double, make the double negative, then convert back to FixedPoint2
		// h/t to reader EmtyC for this version
		return FixedPoint2 { -static_cast<double>(*this) };
	}

};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp) {
    out << static_cast<double>(fp);
    return out;
}

std::istream& operator>>(std::istream& in, FixedPoint2& fp) {
	double d {};
	in >> d;
	fp = FixedPoint2 { d };
	return in;
}

FixedPoint2 operator+(const FixedPoint2& fp1, const FixedPoint2& fp2) {
	return FixedPoint2 { static_cast<double>(fp1) + static_cast<double>(fp2) };
}

int main() {
	assert(FixedPoint2 { 0.75 } == FixedPoint2 { 0.75 });		// Test equality true
	assert(!(FixedPoint2 { 0.75 } == FixedPoint2 { 0.76 }));	// Test equality false
	// Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
	assert(FixedPoint2 { 0.75 } + FixedPoint2 { 1.23 } == FixedPoint2 { 1.98 });	// both positive, no decimal overflow
	assert(FixedPoint2 { 0.75 } + FixedPoint2 { 1.50 } == FixedPoint2 { 2.25 });	// both positive, with decimal overflow
	assert(FixedPoint2 { -0.75 } + FixedPoint2 { -1.23 } == FixedPoint2 { -1.98 });	// both negative, no decimal overflow
	assert(FixedPoint2 { -0.75 } + FixedPoint2 { -1.50 } == FixedPoint2 { -2.25 });	// both negative, with decimal overflow
	assert(FixedPoint2 { 0.75 } + FixedPoint2 { -1.23 } == FixedPoint2 { -0.48 });	// second negative, no decimal overflow
	assert(FixedPoint2 { 0.75 } + FixedPoint2 { -1.50 } == FixedPoint2 { -0.75 });	// second negative, possible decimal overflow
	assert(FixedPoint2 { -0.75 } + FixedPoint2 { 1.23 } == FixedPoint2 { 0.48 });	// first negative, no decimal overflow
	assert(FixedPoint2 { -0.75 } + FixedPoint2 { 1.50 } == FixedPoint2 { 0.75 });	// first negative, possible decimal overflow
	FixedPoint2 a { -0.48 };
	assert(static_cast<double>(a) == -0.48);
	assert(static_cast<double>(-a) == 0.48);
	std::cout << "Enter a number: ";	// enter 5.678
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	assert(static_cast<double>(a) == 5.68);

	return 0;
}