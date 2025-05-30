// https://www.learncpp.com/cpp-tutorial/chapter-21-summary-and-quiz

/*
Now add a constructor that takes a double. The follow program should run:

```
#include <cassert>
#include <iostream>

int main()
{
	FixedPoint2 a{ 0.01 };
	assert(static_cast<double>(a) == 0.01);

	FixedPoint2 b{ -0.01 };
	assert(static_cast<double>(b) == -0.01);

	FixedPoint2 c{ 1.9 }; // make sure we handle single digit decimal
	assert(static_cast<double>(c) == 1.9);

	FixedPoint2 d{ 5.01 }; // stored as 5.0099999... so we'll need to round this
	assert(static_cast<double>(d) == 5.01);

	FixedPoint2 e{ -5.01 }; // stored as -5.0099999... so we'll need to round this
	assert(static_cast<double>(e) == -5.01);

	// Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
	FixedPoint2 f { 106.9978 }; // should be stored with base 107 and decimal 0
	assert(static_cast<double>(f) == 107.0);

	// Handle case where the argument's decimal rounds to -100 (need to decrease base by 1)
	FixedPoint2 g { -106.9978 }; // should be stored with base -107 and decimal 0
	assert(static_cast<double>(g) == -107.0);

	return 0;
}
```

Recommendation: This one will be a bit tricky. Do this one in three steps. First, solve for the cases where the double parameter is representable directly (variables a through c above). Then, update your code to handle the cases where the double parameter has a rounding error (variables d & e). Variables f and g should be handled by the overflow handling we added in the prior step.

For all cases:
Hint: You can move a digit from the right of the decimal to the left of the decimal by multiplying by 10. Multiply by 100 to move two places.

For variables a through c:
Hint: You can get the non-fractional part of a double by static casting the double to an integer. To get the fractional part, you can subtract out the base part.

For variables d & e:
Hint: You can round a number (on the left of the decimal) by using the std::round() function (included in header <cmath>), and take the floor of the number (towards zero) using std::trunc().
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

};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp) {
    out << static_cast<double>(fp);
    return out;
}

int main() {
	FixedPoint2 a { 0.01 };
	std::cout << a << '\n';
	assert(static_cast<double>(a) == 0.01);
	FixedPoint2 b { -0.01 };
	assert(static_cast<double>(b) == -0.01);
	FixedPoint2 c { 1.9 };	// make sure we handle single digit decimal
	assert(static_cast<double>(c) == 1.9);
	FixedPoint2 d { 5.01 };	// stored as 5.0099999... so we'll need to round this
	assert(static_cast<double>(d) == 5.01);
	FixedPoint2 e{ -5.01 };	// stored as -5.0099999... so we'll need to round this
	assert(static_cast<double>(e) == -5.01);
	// Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
	FixedPoint2 f { 106.9978 };	// should be stored with base 107 and decimal 0
	assert(static_cast<double>(f) == 107.0);
	// Handle case where the argument's decimal rounds to -100 (need to decrease base by 1)
	FixedPoint2 g { -106.9978 };	// should be stored with base -107 and decimal 0
	assert(static_cast<double>(g) == -107.0);

	return 0;
}