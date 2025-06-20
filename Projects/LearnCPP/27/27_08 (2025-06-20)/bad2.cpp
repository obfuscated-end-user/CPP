// https://www.learncpp.com/cpp-tutorial/exception-dangers-and-downsides

#include <iostream>

try {
    openFile(filename);
    writeFile(filename, data);
}
catch (const FileException& exception) {
    std::cerr << "Failed to write to file: " << exception.what() << '\n';
}

// Make sure file is closed
closeFile(filename);