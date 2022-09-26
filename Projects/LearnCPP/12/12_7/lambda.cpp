// https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/

#include <iostream>

int main() {
    [] {};  // a lambda with an omitted return type, no captures, and omitted parameters.

    return 0;
}

/*
lambda expression syntax:

[ captureClause ] ( parameters ) -> returnType
{
    statements;
}
*/