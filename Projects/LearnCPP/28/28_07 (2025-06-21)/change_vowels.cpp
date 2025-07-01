// https://www.learncpp.com/cpp-tutorial/random-file-io

#include <fstream>
#include <iostream>
#include <string>

int main() {
	// Note we have to specify both in and out because we're using fstream
	std::fstream iofile { "Sample.txt", std::ios::in | std::ios::out };

	// If we couldn't open iofile, print an error
	if (!iofile) {
		// Print an error and exit
		std::cerr << "Uh oh, Sample.txt could not be opened!\n";
		return 1;
	}

	char chChar {}; // we're going to do this character by character

	// While there's still data to process
	while (iofile.get(chChar)) {
		switch (chChar) {
			// If we find a vowel
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':

				// Back up one character
				iofile.seekg(-1, std::ios::cur);

				// Because we did a seek, we can now safely do a write, so
				// let's write a # over the vowel
				iofile << '#';

				// Now we want to go back to read mode so the next call
				// to get() will perform correctly.  We'll seekg() to the current
				// location because we don't want to move the file pointer.
				iofile.seekg(iofile.tellg(), std::ios::beg);

				break;
		}
	}

	return 0;
}

// Doesn't work for me.
// Change the text file back to this vvv after running the program.
/*
This is line 1
This is line 2
This is line 3
This is line 4
*/