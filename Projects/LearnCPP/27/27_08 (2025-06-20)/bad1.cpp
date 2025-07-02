// https://www.learncpp.com/cpp-tutorial/exception-dangers-and-downsides

#include <iostream>

try {
	openFile(filename);
	writeFile(filename, data);
	closeFile(filename);
} catch (const FileException& exception) {
	std::cerr << "Failed to write to file: " << exception.what() << '\n';
}