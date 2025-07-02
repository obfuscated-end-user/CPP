// https://www.learncpp.com/cpp-tutorial/chapter-21-summary-and-quiz

/*
Now let’s handle the case where the fractional portion is out of bounds. We have two reasonable strategies here:

	Clamp the fraction portion (if >99, set to 99).
	Treat overflow as relevant (if >99, reduce by 100 and add 1 to base).

In this exercise, we’ll treat decimal overflow as relevant, as this will be useful in the next step.

The following should run:

```
#include <cassert>
#include <iostream>

// You will need to make testDecimal a friend of FixedPoint2
// so the function can access the private members of FixedPoint2
bool testDecimal(const FixedPoint2 &fp)
{
	if (fp.m_base >= 0)
		return fp.m_decimal >= 0 && fp.m_decimal < 100;
	else
		return fp.m_decimal <= 0 && fp.m_decimal > -100;
}

int main()
{
	FixedPoint2 a{ 1, 104 };
	std::cout << a << '\n';
	std::cout << static_cast<double>(a) << '\n';
	assert(static_cast<double>(a) == 2.04);
	assert(testDecimal(a));

	FixedPoint2 b{ 1, -104 };
	assert(static_cast<double>(b) == -2.04);
	assert(testDecimal(b));

	FixedPoint2 c{ -1, 104 };
	assert(static_cast<double>(c) == -2.04);
	assert(testDecimal(c));

	FixedPoint2 d{ -1, -104 };
	assert(static_cast<double>(d) == -2.04);
	assert(testDecimal(d));

	return 0;
}
```

And produce the output:

```
2.04
2.04
```

Hint: To output your number, static_cast it to a double.
*/


#include <cassert>
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

		// If decimal is out of bounds (in either direction),
		// adjust the decimal so it's in bounds
		// and adjust base to account for the number of units removed from the decimal
		// h/t to reader David Pinheiro for simplifying this
		m_base += m_decimal / 100;		// integer division
		m_decimal = m_decimal % 100;	// integer remainder
	}

	explicit operator double() const {
		return m_base + (static_cast<double>(m_decimal) / 100);
	}

	friend bool testDecimal(const FixedPoint2& fp);
};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp) {
	out << static_cast<double>(fp);
	return out;
}

// You will need t make testDecimal a friend of FixedPoint2
// so the function can access the private members of FixedPoint2
bool testDecimal(const FixedPoint2& fp) {
	if (fp.m_base >= 0)
		return fp.m_decimal >= 0 && fp.m_decimal < 100;
	else
		return fp.m_decimal <= 0 && fp.m_decimal > -100;
}

int main() {
	FixedPoint2 a { 1, 104 };
	std::cout << a << '\n';
	std::cout << static_cast<double>(a) << '\n';
	assert(static_cast<double>(a) == 2.04);
	assert(testDecimal(a));

	FixedPoint2 b { 1, -104 };
	assert(static_cast<double>(b) == -2.04);
	assert(testDecimal(b));

	FixedPoint2 c { -1, 104 };
	assert(static_cast<double>(c) == -2.04);
	assert(testDecimal(c));

	FixedPoint2 d { -1, -104 };
	assert(static_cast<double>(d) == -2.04);
	assert(testDecimal(d));

	return 0;
}