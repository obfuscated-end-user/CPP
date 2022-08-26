// https://www.learncpp.com/cpp-tutorial/intro-to-loops-and-while-statements/

/*
Invert the nested loops example so it prints the following:

5 4 3 2 1
4 3 2 1
3 2 1
2 1
1
*/

/*
// solution

// Loop between 5 and 1
int main()
{
	int outer{ 5 };
	while (outer >= 1)
	{
		// loop between outer and 1
		int inner{ outer };
		while (inner >= 1)
        {
			std::cout << inner-- << ' ';
        }

		// print a newline at the end of each row
		std::cout << '\n';
		--outer;
	}

	return 0;
}
*/

#include <iostream>

int main() {
    int outer = 5;
    while (outer >= 1) {
        int inner = outer;
        while (inner >= 1)
            std::cout << inner-- << ' ';
        std::cout << '\n';
        --outer;
    }
    return 0;
}