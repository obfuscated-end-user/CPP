// https://www.learncpp.com/cpp-tutorial/chapter-26-summary-and-quiz

/*
	Write a Pair class that allows you to specify separate types for each of the two values in the pair.

Note: We’re naming this class differently from the previous one because C++ does not currently allow you to “overload” classes that differ only in the number or type of template parameters.

The following program should work:

```
int main()
{
	Pair<int, double> p1 { 5, 6.7 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2 { 2.3, 4 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
```

and print:

```
Pair: 5 6.7
Pair: 2.3 4
```

Hint: To define a template using two different types, separate the two types by a comma in the template parameter declaration. See lesson 11.8 -- Function templates with multiple template types for more information.
*/

#include <iostream>

template <typename T, typename S>
class Pair {
private:
	T m_x {};
	S m_y {};

public:
	Pair(const T& x, const S& y)
		: m_x { x }, m_y { y } {}

	T& first() {
		return m_x;
	}

	S& second() {
		return m_y;
	}

	const T& first() const {
		return m_x;
	}

	const S& second() const {
		return m_y;
	}
};

int main() {
	Pair<int, double> p1 { 5, 6.7 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2 { 2.3, 4 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}