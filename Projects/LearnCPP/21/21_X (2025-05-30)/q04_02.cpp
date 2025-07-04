// https://www.learncpp.com/cpp-tutorial/chapter-21-summary-and-quiz

/*
Write a class named FixedPoint2 that implements the recommended solution from the previous question. If either (or both) of the non-fractional and fractional part of the number are negative, the number should be treated as negative. Provide the overloaded operators and constructors required for the following program to run. For now, don’t worry about the fractional portion being out of bounds (>99 or <-99).

```
#include <cassert>
#include <iostream>

int main()
{
	FixedPoint2 a{ 34, 56 };
	std::cout << a << '\n';
	std::cout << static_cast<double>(a) << '\n';
	assert(static_cast<double>(a) == 34.56);

	FixedPoint2 b{ -2, 8 };
	assert(static_cast<double>(b) == -2.08);

	FixedPoint2 c{ 2, -8 };
	assert(static_cast<double>(c) == -2.08);

	FixedPoint2 d{ -2, -8 };
	assert(static_cast<double>(d) == -2.08);

	FixedPoint2 e{ 0, -5 };
	assert(static_cast<double>(e) == -0.05);

	FixedPoint2 f{ 0, 10 };
	assert(static_cast<double>(f) == 0.1);

	return 0;
}
```

This program should produce the result:

```
34.56
34.56
```

Hint: To output your number, static_cast it to a double.
*/


#include <cassert>
#include <cstdint>	// for fixed width integers
#include <iostream>

class FixedPoint2 {
private:
	std::int16_t m_base {};	 // here's our non-fractional part
	std::int8_t m_decimal {};	// here's our fractional part

public:
	FixedPoint2(std::int16_t base=0, std::int8_t decimal=0)
		: m_base { base }, m_decimal { decimal } {
		
		// If either (or both) of the non-fractional and fractional part of the number are negative, the number should be treated as negative
		if (m_base < 0 || m_decimal < 0) {
			// Make sure base is negative
			if (m_base > 0)
				m_base = -m_base;
			// Make sure decimal is negative
			if (m_decimal > 0)
				m_decimal = -m_decimal;
		}
	}

	explicit operator double() const {
		return m_base + (static_cast<double>(m_decimal) / 100);
	}
};

// This doesn't require access to the internals of the class, so it can be defined outside the class
std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp) {
	out << static_cast<double>(fp);
	return out;
}

int main() {
	FixedPoint2 a { 34, 56 };
	std::cout << a << '\n';
	std::cout << static_cast<double>(a) << '\n';
	assert(static_cast<double>(a) == 34.56);

	FixedPoint2 b { -2, 8 };
	assert(static_cast<double>(b) == -2.08);

	FixedPoint2 c { 2, -8 };
	assert(static_cast<double>(c) == -2.08);

	FixedPoint2 d { -2, -8 };
	assert(static_cast<double>(d) == -2.08);

	FixedPoint2 e { 0, -5 };
	assert(static_cast<double>(e) == -0.05);

	FixedPoint2 f { 0, 10 };
	assert(static_cast<double>(f) == 0.1);

	return 0;
}