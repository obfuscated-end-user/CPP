// https://www.learncpp.com/cpp-tutorial/chapter-11-comprehensive-quiz/

/*
Question #5

What’s wrong with each of these snippets, and how would you fix it?

d)

int* allocateArray(const int length)
{
    int temp[length]{};
    return temp;
}
*/

// returns an int pointer, and wall we homies know that c++ goes full retard with array pointers and memory leak and shit because you never delete it.
int* allocateArray(const int length) {
    int temp[length]{};
    return temp;
}

/*
temp is a fixed array, but length is not a compile-time constant, so we can’t use length to create a C-style array. Variable temp will also go out of scope at the end of the function, the return value will be pointing to something invalid. temp should use dynamic memory allocation or be a std::vector.
*/