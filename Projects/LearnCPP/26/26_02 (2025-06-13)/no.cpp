// https://www.learncpp.com/cpp-tutorial/template-non-type-parameters

template <int size>
class Foo {};

int main() {
	int x { 4 };	// x is non-constexpr
	Foo<x> f;		// error: the template non-type argument must be constexpr

	return 0;
}