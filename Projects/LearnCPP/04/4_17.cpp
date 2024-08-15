// https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring
// 2024/08/12 - Moved to "5.9 — Introduction to std::string"

#include <iostream>
#include <string> // allows use of std::string
#include <string_view> // for std::string_view

using namespace std::literals;

int main() {
    std::cout << "Hello, world!\n";
    // std::string name { "Mark" }; // initialize name with string literal "Mark"
    // name = "John";              // change name to "John"

    /* std::cout << "Enter your full name: ";
    std::string name{};
    std::cin >> name; // this won't work as expected since std::cin breaks on whitespace

    std::cout << "Enter your age: ";
    std::string age{};
    std::cin >> age;

    std::cout << "Your name is " << name << " and your age is " << age << '\n'; */

    std::cout << "Enter your full name: ";
    std::string name{};
    // The std::ws input manipulator tells std::cin to ignore any leading whitespace before extraction.
    // If using std::getline() to read strings, use std::cin >> std::ws input manipulator to ignore leading whitespace.
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your age: ";
    std::string age{};
    std::getline(std::cin >> std::ws, age); // read a full line of text into age

    std::cout << "Your name is " << name << " and your age is " << age << '\n';
    std::cout << name << " has " << name.length() << " characters\n";

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal

    std::cout << "moo\n"sv; // sv suffix is a std::string_view literal
    return 0;
}