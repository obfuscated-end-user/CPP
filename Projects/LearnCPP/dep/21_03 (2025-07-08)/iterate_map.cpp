// https://www.learncpp.com/cpp-tutorial/stl-iterators-overview

#include <iostream>
#include <map>
#include <string>

int main() {
	std::map<int, std::string> myMap {};
	myMap.insert(std::make_pair(4, "apple"));
	myMap.insert(std::make_pair(2, "orange"));
	myMap.insert(std::make_pair(1, "banana"));
	myMap.insert(std::make_pair(3, "grapes"));
	myMap.insert(std::make_pair(6, "mango"));
	myMap.insert(std::make_pair(5, "peach"));

	auto it { myMap.cbegin() };		// declare a const iterator and assign to start of vector
	while (it != myMap.cend()) {	// while it hasn't reach the end
		std::cout << it->first << '=' << it->second << ' ';	// print the value of the element it points to
		++it;	// and iterate to the next element
	}

	std::cout << '\n';

	return 0;
}