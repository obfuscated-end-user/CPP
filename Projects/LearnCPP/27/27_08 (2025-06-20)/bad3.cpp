// https://www.learncpp.com/cpp-tutorial/exception-dangers-and-downsides

#include <iostream>

try {
    auto* john { new Person { "John", 18, PERSON_MALE } };
    processPerson(john);
    delete john;
} catch (const PersonException& exception) {
    std::cerr << "Failed to process person: " << exception.what() << '\n';
}