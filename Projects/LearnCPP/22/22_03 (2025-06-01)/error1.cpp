// https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment

#include <iostream>
#include <string>
#include <string_view>

class Name {
private:
	std::string m_name {};

public:
	Name(std::string_view name) : m_name { name } {}

	Name(const Name& name) = delete;
	Name& operator=(const Name& name) = delete;
	Name(Name&& name) = delete;
	Name& operator=(Name&& name) = delete;

	const std::string& get() const {
		return m_name;
	}
};

int main() {
	Name n1 { "Bob" };
	n1 = Name { "Joe" };	// error: move assignment deleted

	std::cout << n1.get() << '\n';

	return 0;
}