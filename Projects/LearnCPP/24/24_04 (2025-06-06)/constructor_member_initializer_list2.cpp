// https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes

#include <iostream>
#include <string>
#include <string_view>

class Person {
public:
	std::string m_name;
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
public:
	double m_battingAverage {};
	int m_homeRuns {};

	BaseballPlayer(std::string_view name="", int age=0,
		double battingAverage=0.0, int homeRuns=0)
		: Person { name, age }	// call Person(std::string_view, int) to initialize these fields
		, m_battingAverage { battingAverage }
		, m_homeRuns { homeRuns } {}

	double getBattingAverage() const {
		return m_battingAverage;
	}

	int getHomeRuns() const {
		return m_homeRuns;
	}
};

int main() {
	BaseballPlayer pedro { "Pedro Cerrano", 32, 0.342, 42 };

	std::cout << pedro.getName() << '\n';
	std::cout << pedro.getAge() << '\n';
	std::cout << pedro.getBattingAverage() << '\n';
	std::cout << pedro.getHomeRuns() << '\n';

	return 0;
}