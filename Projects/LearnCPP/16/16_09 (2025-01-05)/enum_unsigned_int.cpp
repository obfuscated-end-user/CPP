// https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators

#include <vector>

namespace Students {
	enum Names : unsigned int { // explicitly specifies the underlying type is unsigned int
		kenny,			// 0
		kyle,			// 1
		stan,			// 2
		butters,		// 3
		cartman,		// 4
		max_students	// 5
	};
}

int main() {
	std::vector testScores { 78, 94, 66, 77, 14 };
	Students::Names name { Students::stan };	// non-constexpr

	testScores[name] = 76;	// not a sign conversion since name is unsigned

	return 0;
}