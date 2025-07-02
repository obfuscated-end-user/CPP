// https://www.learncpp.com/cpp-tutorial/exception-dangers-and-downsides

#include <iostream>

Person* john{ nullptr };

try {
	john = new Person("John", 18, PERSON_MALE);
	processPerson(john);
} catch (const PersonException& exception) {
	std::cerr << "Failed to process person: " << exception.what() << '\n';
}

delete john;