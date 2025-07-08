// https://www.learncpp.com/cpp-tutorial/stl-iterators-overview

#include <iostream>
#include <set>

int main() {
	std::set<int> mySet {};
	mySet.insert(7);
	mySet.insert(2);
	mySet.insert(-6);
	mySet.insert(8);
	mySet.insert(1);
	mySet.insert(-4);

	std::set<int>::const_iterator it;	// declare an iterator
	it = mySet.cbegin();	// assign it to the start of the set
	while (it != mySet.cend()) {	// while it hans't reach the end
		std::cout << *it << ' ';	// print the value of the element it points to
		++it;	// and iterate to the next element
	}

	std::cout << '\n';

	return 0;
}