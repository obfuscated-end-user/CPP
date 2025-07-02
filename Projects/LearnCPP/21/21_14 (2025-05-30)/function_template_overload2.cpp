// https://www.learncpp.com/cpp-tutorial/overloading-operators-and-function-templates

#include <iostream>

template <typename T>
T average(const T* myArray, int numValues) {
	T sum { 0 };
	for (int count { 0 }; count < numValues; ++count)
		sum += myArray[count];

	sum /= numValues;
	return sum;
}

class Cents {
private:
	int m_cents {};

public:
	Cents (int cents) : m_cents { cents } {}

	friend std::ostream& operator<<(std::ostream& out, const Cents& cents) {
		out << cents.m_cents << " cents";
		return out;
	}

	Cents& operator+=(const Cents& cents) {
		m_cents += cents.m_cents;
		return *this;
	}

	Cents& operator/=(const Cents& cents) {
		m_cents /= cents.m_cents;
		return *this;
	}
};

int main() {
	int intArray[] { 5, 3, 2, 1, 4 };
	std::cout << average(intArray, 5) << '\n';

	double doubleArray[] { 3.12, 3.45, 9.23, 6.34 };
	std::cout << average(doubleArray, 4) << '\n';

	Cents centsArray[] { Cents { 5 }, Cents { 10 }, Cents { 15 }, Cents { 14 } };
	std::cout << average(centsArray, 4) << '\n';

	return 0;
}