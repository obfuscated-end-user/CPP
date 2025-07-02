// https://www.learncpp.com/cpp-tutorial/command-line-arguments

#include <iostream>
#include <sstream>  // for std::stringstream
#include <string>

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		// On some operating systems, argv[0] can end up as an empty string instead of the program's name.
		// We'll conditionalize our response on whether argv[0] is empty or not.
		if (argv[0])
			std::cout << "Usage: " << argv[0] << " <number>" << '\n';
		else
			std::cout << "Usage: <program name> <number>" << '\n';

		return 1;
	}

	std::stringstream convert { argv[1] };  // set up a stringstream variable named convert, initialized with the input from argv[1]

	int myInt {};
	if (!(convert >> myInt))	// do the conversion
		myInt = 0;  // if conversion fails, set myInt to a default value

	std::cout << "Got integer: " << myInt << '\n';

	return 0;
}
// .\numargs 567