// https://www.learncpp.com/cpp-tutorial/command-line-arguments

#include <iostream>
#include <sstream>  // for std::stringstream
#include <string>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        // On some operating systems, argv[0] can end up as an empty string instead of the program's name.
        // We'll conditionalize our response whether argv[0] is empty or not.
        if (argv[0])
            std::cout << "Usage: " << argv[0] << " <number>" << '\n';
        else
            std::cout << "Usage: <program name> <number>\n";
        return 1;
    }

    // has to be std::stringstream convert { argv[1] }; not std::stringstream convert = argv[1];
    std::stringstream convert { argv[1] }; // set up a stringstream variable named convert, initialized with the input from argv[1]

    int myint;
    // stringstream works like std::cin, so you can use operator>> with it
    if (!(convert >> myint))    // do the conversion
        myint = 0;
    std::cout << "Got integer: " << myint << '\n';

    return 0;
}

// maybe try compiling this program and run it with command prompt? i don't know what i am talking about, but hey, it might make more sense if i did it like that instead of running it directly on vs code though