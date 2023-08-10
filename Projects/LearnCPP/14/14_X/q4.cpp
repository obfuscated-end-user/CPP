// https://www.learncpp.com/cpp-tutorial/chapter-14-comprehensive-quiz

#include <cmath>
#include <cstdint>
#include <iostream>

class FixedPoint2 {
private:
    std::int16_t m_base;
    std::int8_t m_decimal;

public:
    FixedPoint2(std::int16_t base=0, std::int8_t decimal=0):
        m_base {base}, m_decimal {decimal} {
        if (m_base < 0 || m_decimal < 0) {
            if (m_base > 0)
                m_base = -m_base;
            if (m_decimal > 0)
                m_decimal = -m_decimal;
        }
    }

    FixedPoint2(double d):
        m_base {static_cast<std::int16_t>(std::trunc(d))},
        m_decimal {static_cast<std::int8_t>(std::round(d * 100))} {}

    operator double() const {
        return m_base + (static_cast<double>(m_decimal) / 100);
    }

    friend bool operator== (const FixedPoint2& fp1, const FixedPoint2& fp2) {
        return fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal;
    }

    FixedPoint2 operator-() const {
        return { static_cast<std::int16_t>(-m_base), static_cast<std::int8_t>(-m_decimal) };
    }
};

std::ostream& operator<< (std::ostream& out, const FixedPoint2& fp) {
    out << static_cast<double>(fp);
    return out;
}

std::istream& operator>>(std::istream& in, FixedPoint2& fp) {
    double d;
    in >> d;
    fp = FixedPoint2 {d};
    return in;
}

FixedPoint2 operator+(const FixedPoint2& fp1, const FixedPoint2& fp2) {
    return static_cast<double>(fp1) + static_cast<double>(fp2);
}

void testAddition() {
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}

int main() {
	FixedPoint2 a{ 34, 56 };
	std::cout << a << '\n';

	FixedPoint2 b{ -2, 8 };
	std::cout << b << '\n';

	FixedPoint2 c{ 2, -8 };
	std::cout << c << '\n';

	FixedPoint2 d{ -2, -8 };
	std::cout << d << '\n';

	FixedPoint2 e{ 0, -5 };
	std::cout << e << '\n';

	std::cout << static_cast<double>(e) << '\n';

    // Handle cases where the argument is representable directly
    FixedPoint2 f{ 0.01 };
    std::cout << f << '\n';
    FixedPoint2 g{ -0.01 };
    std::cout << g << '\n';
    // Handle cases where the argument has some rounding error
    FixedPoint2 h{ 5.01 }; // stored as 5.0099999... so we'll need to round this
    std::cout << h << '\n';
    FixedPoint2 i{ -5.01 }; // stored as -5.0099999... so we'll need to round this
    std::cout << i << '\n';
    // Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
    FixedPoint2 j{ 106.9978 }; // should be stored with base 107 and decimal 0
    std::cout << j << '\n';
    FixedPoint2 k{ 1.9 }; // make sure we handle single digit decimal
    std::cout << k;

    testAddition();

    FixedPoint2 l{ -0.48 };
    std::cout << l << '\n';
    std::cout << -l << '\n';
    std::cout << "Enter a number: "; // enter 5.678
    std::cin >> l;
    std::cout << "You entered: " << l << '\n';

    std::cout << '\n' << std::round(-INFINITY);
    std::cout << '\n' << std::trunc(INFINITY / INFINITY);

	return 0;
}