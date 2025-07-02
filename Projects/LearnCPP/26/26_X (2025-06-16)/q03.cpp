// https://www.learncpp.com/cpp-tutorial/chapter-26-summary-and-quiz

/*
	A string-value pair is a special type of pair where the first value is always a string type, and the second value can be any type. Write a template class named StringValuePair that inherits from a partially specialized Pair class (using std::string as the first type, and allowing the user to specify the second type).

The following program should run:

```
int main()
{
	StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}
```

and print:

```
Pair: Hello 5
```

Hint: When you call the Pair constructor from the StringValuePair constructor, don’t forget to include the template parameters as part of the Pair class name.
*/

#include <iostream>
#include <string>
#include <string_view>

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

template <typename S>
class StringValuePair : public Pair<std::string, S> {
public:
	StringValuePair(std::string_view key, const S& value)
				// a std::string_view won't implicitly convert to a std::string, we must be explicit
		: Pair<std::string, S> { static_cast<std::string>(key), value } {}
};

int main() {
	StringValuePair<int> svp{ "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}