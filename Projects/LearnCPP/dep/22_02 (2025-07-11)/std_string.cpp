// https://www.learncpp.com/cpp-tutorial/stdstring-construction-and-destruction

#include <iostream>
#include <string>

int main() {
	// default constructor
	std::string sSource1;
	std::cout << sSource1;

	// copy constructor
	std::string sSource2 { "my string" };
	std::string sOutput1 { sSource2 };
	std::cout << sOutput1 << '\n';

	// what
	std::string sSource3 { "my string" };
	std::string sOutput2 { sSource3, 3 };
	std::cout << sOutput2 << '\n';
	std::string sOutput3(sSource3, 3, 4);
	std::cout << sOutput3 << '\n';

	// hmmm
	const char* szSource1 { "my string" };
	std::string sOutput4 { szSource1 };
	std::cout << sOutput4 << '\n';

	// insert explanation here
	const char* szSource2 { "my string" };
	std::string sOutput5(szSource2, 4);
	std::cout << sOutput5 << '\n';

	// queue
	std::string sOutput6(4, 'Q');
	std::cout << sOutput6 << '\n';

	return 0;
}