// https://www.learncpp.com/cpp-tutorial/command-line-arguments

#include <iostream>

// argc is an int parameter containing the number of arguments passed to  the program. (argc = "argument count") it will always be at least 1, because the first argument is always the name of the program itself. each command line argument the user provides will cause argc to increase by 1.
// argv is where the actual argument values are stored. (argv = "argument values", but the proper name is "argument vectors"). argv is just an array of c-style strings. the length of this array is argc.
int main(int argc, char* argv[]) {
    std::cout << "There are " << argc << " arguments:\n";

    // Loop through each argument and print its number and value
    for (int count = 0; count < argc; ++count)
    // argv[count] is a char* array remember that
        std::cout << count << ' ' << argv[count] << '\n';

    return 0;
}

/*
since i wrote all of this in vs code, where there is this thing every time i run the program:
"PS E:\Projects\CPP> cd "e:\Projects\CPP\Projects\LearnCPP\12\12_5\" ; if ($?) { g++ main_argc_argv.cpp -o main_argc_argv } ; if ($?) { .\main_argc_argv }"

i can't pass in the arguments directly because i'm either too stupid or that it is not allowed to be done in vs code
whatever what the hell just learn this and it will eventually go away
*/