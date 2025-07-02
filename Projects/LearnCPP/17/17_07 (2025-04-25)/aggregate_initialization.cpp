// https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays

int main() {
	int fibonacci[6] = { 0, 1, 1, 2, 3, 5 };	// copy-list initialization using braced list
	int prime[5] { 2, 3, 5, 7, 11 };			// list initialization using braced list (preferred)

	int arr1[5];	// Members default value initialized (int elements are left uninitialized)
	int arr2[5] {};	// Members value initialized (int elements are zero uninitialized) (preferred)

	// int a[4] { 1, 2, 3, 4, 5 }; // compile error: too many initializers
	int b[4] { 1, 2 };			// arr[2] and arr[3] are value initialized

	// auto squares[5] { 1, 4, 9, 16, 25 };	// compile error: can't use type deduction on C-style arrays

	return 0;
}