// https://www.learncpp.com/cpp-tutorial/basic-file-io

#include <iostream>
#include <fstream>

int main() {
	std::ofstream outf { "Sample.txt" };
	outf << "This is line 1\n";
	outf << "This is line 2\n";
	outf.close();	// explicitly close the file

	// Oops, we forgot something
	outf.open("Sample.txt", std::ios::app);
	outf << "This is line 3\n";
	outf.close();

	return 0;
}