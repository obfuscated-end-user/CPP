// https://www.learncpp.com/cpp-tutorial/chapter-6-summary-and-quiz/

/*
#include <iostream>

int main()
{
	std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");

	return 0;
}
*/

#include <iostream>

bool passOrFail () {
    static int x = 0;
    if (x < 3) {
        x++;
        return 1;
    }
    return 0;
}

/*
// solution on site:
bool passOrFail() {
	static int s_passes = 3;
	--s_passes;
	return (s_passes >= 0);
}
*/

int main() {
	std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");
	return 0;
}