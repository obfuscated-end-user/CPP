// https://www.learncpp.com/cpp-tutorial/intro-to-loops-and-while-statements/

/*
Now make the numbers print like this:

        1
      2 1
    3 2 1
  4 3 2 1
5 4 3 2 1

Hint: Figure out how to make it print like this first:

X X X X 1
X X X 2 1
X X 3 2 1
X 4 3 2 1
5 4 3 2 1
*/

/*
// solution
// Thanks to Shiva for this solution
#include <iostream>

int main()
{
	// There are 5 rows, we can loop from 1 to 5
	int outer{ 1 };

	while (outer <= 5)
	{
		// Row elements appear in descending order, so start from 5 and loop through to 1
		int inner{ 5 };

		while (inner >= 1)
		{
			// The first number in any row is the same as the row number
			// So number should be printed only if it is <= the row number, space otherwise
			if (inner <= outer)
				std::cout << inner << ' '; // print the number and a single space
			else
				std::cout << "  "; // don't print a number, but print two spaces

			--inner;
		}

		// A row has been printed, move to the next row
		std::cout << '\n';

		++outer;
	}

	return 0;
}
*/

#include <iostream>

// lol fuck doing this
int main() {
	int outer = 1;
	while (outer <= 5) {
		int inner = 5;
		while (inner >= 1) {
			if (inner <= outer)
				std::cout << inner << ' ';
			else
				std::cout << "  ";
			--inner;
		}
		std::cout << '\n';
		++outer;
	}
	return 0;
}