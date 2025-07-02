// https://www.learncpp.com/cpp-tutorial/composition

#include <string>
#include <iostream>
#include "Creature.h"
#include "Point2D.h"

int main() {
	std::cout << "Enter a name for your creature: ";
	std::string name;
	std::cin >> name;
	Creature creature {name, {4, 7}};

	while (true) {
		std::cout << creature << '\n';

		std::cout << "Enter the new X location for creture (-1 to quit): ";
		int x = 0;
		std::cin >> x;
		if (x == -1)
			break;

		std::cout << "Enter the new Y location for creture (-1 to quit): ";
		int y = 0;
		std::cin >> y;
		if (y == -1)
			break;

		creature.moveTo(x, y);
	}

	return 0;
}