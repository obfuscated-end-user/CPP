// https://www.learncpp.com/cpp-tutorial/circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr

// h/t tp reader Waldo for an early version of this example
#include <iostream>
#include <memory>

class Resource {
public:
	Resource() {
		std::cout << "Resource acquired\n";
	}

	~Resource() {
		std::cout << "Resource destroyed\n";
	}
};

// Returns a std::weak_ptr to an invalid object
std::weak_ptr<Resource> getWeakPtr() {
	auto ptr { std::make_shared<Resource>() };
	return std::weak_ptr<Resource> { ptr };
}	// ptr goes out of scope, Resource destroyed

// Returns a dumb pointer to an invalid object
Resource* getDumbPtr() {
	auto ptr { std::make_unique<Resource>() };
	return ptr.get();
}	// ptr goes out of scope, Resource destroyed

int main() {
	auto dumb { getDumbPtr() };
	std::cout << "Our dumb ptr is: " << ((dumb == nullptr) ? "nullptr\n" : "non-null\n");

	auto weak { getWeakPtr() };
	std::cout << "Our weak ptr is: " << ((weak.expired()) ? "expired\n" : "valid\n");

	return 0;
}