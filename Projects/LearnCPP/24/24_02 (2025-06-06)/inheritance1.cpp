// https://www.learncpp.com/cpp-tutorial/basic-inheritance-in-c

#include <iostream>
#include <string>
#include <string_view>

class Person {
public:
// In this example, we're making our members public for simplicity
	std::string m_name {};
	int m_age {};

	Person(std::string_view name="", int age=0)
		: m_name { name }, m_age { age } {}

	const std::string& getName() const {
		return m_name;
	}

	int getAge() const {
		return m_age;
	}
};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person {
// In this example, we're making our members public for simplicity
public:
	double m_battingAverage {};
	int m_homeRuns {};

	BaseballPlayer(double battingAverage=0.0, int homeRuns=0)
		: m_battingAverage { battingAverage }, m_homeRuns { homeRuns } {}
};

int main() {
	// Create a new BaseballPLayer object
	BaseballPlayer joe {};
	// Assign it a name (we can do this directly because m_name is public)
	joe.m_name = "Joe";
	// Print out the name
	std::cout << joe.getName() << '\n'; // use the getName() function we've acquired from the Person base class

	return 0;
}