// https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator

#include <cassert>	// for assert()
#include <iterator>	// for std::size()

class IntList {
private:
	int m_list[10] {};

public:
	int& operator[](int index) {
		assert(index >= 0 && static_cast<std::size_t>(index) < std::size(m_list));

		return m_list[index];
	}
};

int main() {
	IntList list {};
	list[11] = 3;

	return 0;
}