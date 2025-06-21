// https://www.learncpp.com/cpp-tutorial/random-file-io

#include <fstream>
#include <iostream>
#include <string>

int main() {
    // std::ifstream inf { "Sample.txt" };
    std::ifstream inf { "Sample.txt", std::ifstream::binary };

    // If we couldn't open the input file stream for reading
    if (!inf) {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
        return 1;
    }

    std::string strData;

    inf.seekg(5);   // move to 5th character
    // Get the rest of the line and print it, moving to line 2
    std::getline(inf, strData);
    std::cout << strData << '\n';
    std::cout << inf.tellg() << '\n';

    inf.seekg(8, std::ios::cur);    // move 8 more bytes into file
    // Get rest of the line and print it
    std::getline(inf, strData);
    std::cout << strData << '\n';
    std::cout << inf.tellg() << '\n';

    inf.seekg(-14, std::ios::end);  // move 14 bytes before end of file
    // Get rest of the line and print it
    std::getline(inf, strData);     // undefined behavior
    std::cout << strData << '\n';
    std::cout << inf.tellg() << '\n';

    return 0;
}