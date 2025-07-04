// https://www.learncpp.com/cpp-tutorial/aggregation

#include <iostream>
#include <string>

class Teacher {
private:
	std::string m_name;

public:
	Teacher(const std::string& name): m_name { name } {}

	const std::string& getName() const {
		return m_name;
	}
};

class Department {
private:
	const Teacher& m_teacher;

public:
	Department(const Teacher& teacher): m_teacher { teacher } {}
};

int main() {
	// create a teacher outside the scope of the department
	Teacher bob { "Bob" };

	{
		// create a department and use the constructor parameter to pass the teacher to it
		Department department { bob };
	}	// department destroyed here

	// bob still exists here, but the department doesn't
	std::cout << bob.getName() << " still exists!\n";

	return 0;
}