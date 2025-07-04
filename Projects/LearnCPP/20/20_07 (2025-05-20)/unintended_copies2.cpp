// https://www.learncpp.com/cpp-tutorial/lambda-captures

#include <iostream>
#include <functional>	// includes std::reference_wrapper and std::ref

void myInvoke(const std::function<void()>& fn) {
	fn();
}

int main() {
	int i { 0 };

	// Increments and prints its local copy of @i.
	auto count1 { [i]() mutable {
		std::cout << ++i << '\n';
	} };

	// Increments and prints its local copy of @i.
	std::function count2 { [i]() mutable {	// lambda object stored in a std::function
		std::cout << ++i << '\n';
	} };

	myInvoke(count1);
	myInvoke(count1);
	myInvoke(count1);

	std::cout << '\n';

	myInvoke(count2);	// doesn't create copy when called
	myInvoke(count2);	// doesn't create copy when called
	myInvoke(count2);	// doesn't create copy when called

	std::cout << '\n';

	// std::ref(count) ensures count is treated like a reference
	// thus, anything that tries to copy count will actually copy the reference
	// ensuring that only one count exists
	myInvoke(std::ref(count1));
	myInvoke(std::ref(count1));
	myInvoke(std::ref(count1));

	return 0;
}