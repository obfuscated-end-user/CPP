// https://www.learncpp.com/cpp-tutorial/c-style-strings

int main() {
	char str1[8] {};					// an array of 8 char, indices 0 through 7

	const char str2[] { "string" };		// an array of 7 char, indices 0 through 6
	constexpr char str3[] { "hello" };	// an array of 6 const char, indices 0 through 5

	return 0;
}