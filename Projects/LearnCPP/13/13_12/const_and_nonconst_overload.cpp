// https://www.learncpp.com/cpp-tutorial/const-class-objects-and-member-functions

#include <string>
#include <iostream>

class Something {
private:
    std::string m_value {};

public:
    Something(const std::string& value=""): m_value{ value } {}

    // getValue() for const objects (returns const reference)
    const std::string& getValue() const {
        std::cout << "called const reference\n";
        return m_value;
    }
    // getValue() for non-const objects (returns non-const reference)
    std::string& getValue() {
        std::cout << "called non-const reference\n";
        return m_value;
    }
};

int main() {
	Something something;
	something.getValue() = "Hi"; // calls non-const getValue();

	const Something something2;
	something2.getValue(); // calls const getValue();

	return 0;
}