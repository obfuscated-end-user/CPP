// https://www.learncpp.com/cpp-tutorial/function-pointers

int foo(int x) {
	return x;
}

int main() {
	int (*fcnPtr)(int) { &foo };	// Initialize fcnPtr with function foo

	if (fcnPtr) {		// make sure fcnPtr isn't a null pointer
		(*fcnPtr)(5);	// call function foo(5) through fcnPtr.
		fcnPtr(5);	  // otherwise this will lead to undefined behavior
	}
	

	return 0;
}