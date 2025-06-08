// https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz

/*
a) Write an Apple class and a Banana class that are derived from a common Fruit class. Fruit should have two members: a name and a color.

The following program should run:

```
int main()
{
	Apple a{ "red" };
	Banana b{};

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

	return 0;
}
```

And produce the result:

```
My apple is red.
My banana is yellow.
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
public:
    Apple(std::string_view color="red")
        : Fruit { "apple", color } {}
};

class Banana : public Fruit {
public:
    Banana() : Fruit { "banana", "yellow" } {}
};

int main() {
    Apple a { "red" };
    Banana b;
    
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

    return 0;
}