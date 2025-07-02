// https://www.learncpp.com/cpp-tutorial/basic-exception-handling

int main() {
	throw -1;	// throw a literal integer value
	// throw ENUM_INVALID_INDEX;	// throw an enum value
	throw "Can not take square root of negative number";	// throw a literal C-style (const char*) string
	// throw dX;	// throw a double variable that was previously defined
	// throw MyException("Fatal Error");	// Throw an object of class MyException

	return 0;
}