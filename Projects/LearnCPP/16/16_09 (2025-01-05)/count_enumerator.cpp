// https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators

#include <iostream>
#include <vector>

namespace Students {
	enum Names {
		kenny,		  // 0
		kyle,			// 1
		stan,			// 2
		butters,		// 3
		cartman,		// 4
		wendy,		  // 5
		// add future enumerators here
		max_students	// 6
	};
}

int main() {
	std::vector<int> testScores(Students::max_students);	// will now allocate 6 elements

	testScores[Students::stan] = 76;	// still works

	std::cout << "The class has " << Students::max_students << " students\n";

	return 0;
}