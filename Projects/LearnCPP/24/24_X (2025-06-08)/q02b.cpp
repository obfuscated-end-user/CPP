// https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz

/*
b) Add a new class to the previous program called GrannySmith that inherits from Apple.

The following program should run:

```
int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}
```

And produce the result:

```
My apple is red.
My banana is yellow.
My granny smith apple is green.
```
*/

#include <iostream>
#include <string>
#include <string_view>

class Fruit {
private:
	std::string m_name;
	std::string m_color;

public:
	Fruit(std::string_view name, std::string_view color)
		: m_name { name }, m_color { color } {}

	const std::string& getName() const {
		return m_name;
	}

	const std::string& getColor() const {
		return m_color;
	}
};

class Apple : public Fruit {
// The previous constructor we used for Apple had a fixed name ("apple").
// We need a new constructor for GrannySmith to use to set the name of the fruit
protected:
	Apple(std::string_view name, std::string_view color)
		: Fruit { name, color } {}

public:
	Apple(std::string_view color="red")
		: Fruit { "apple", color } {}
};

class Banana : public Fruit {
public:
	Banana() : Fruit { "banana", "yellow" } {}
};

class GrannySmith : public Apple {
public:
	GrannySmith() : Apple { "granny smith apple", "green" } {}
};

int main() {
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}