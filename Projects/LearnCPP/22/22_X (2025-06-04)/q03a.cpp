// https://www.learncpp.com/cpp-tutorial/chapter-22-summary-and-quiz

/*
What’s wrong with the following code? Update the program to be best practices compliant.

```
#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	auto* res{ new Resource{} };
	std::shared_ptr<Resource> ptr1{ res };
	std::shared_ptr<Resource> ptr2{ res };

	return 0;
}
```
*/

#include <iostream>
#include <memory>	// for std::shared_ptr

class Resource {
public:
	Resource() {
		std::cout << "Resource acquired\n";
	}

	~Resource() {
		std::cout << "Resource destroyed\n";
	}
};

int main() {
	auto ptr1 { std::make_shared<Resource>() };
	auto ptr2 { ptr1 };

	return 0;
}