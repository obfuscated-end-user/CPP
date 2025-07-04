// https://www.learncpp.com/cpp-tutorial/circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr

#include <iostream>
#include <memory>	// for std::shared_ptr and std::weak_ptr
#include <string>

class Person {
	std::string m_name;
	std::weak_ptr<Person> m_partner {}; // note: This is now a std::weak_ptr

public:
	Person(const std::string &name) : m_name(name) {
		std::cout << m_name << " created\n";
	}

	~Person() {
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2) {
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

		return true;
	}

	std::shared_ptr<Person> getPartner() const {
		return m_partner.lock();	// use lock() to convert weak_ptr to shared_ptr
	}

	const std::string& getName() {
		return m_name;
	}
};

int main() {
	auto lucy { std::make_shared<Person>("Lucy") };
	auto ricky { std::make_shared<Person>("Ricky") };

	partnerUp(lucy, ricky);

	auto partner = ricky->getPartner(); // get shared_ptr to Ricky's partner
	std::cout << ricky->getName() << "'s partner is: " << partner->getName() << '\n';

	return 0;
}