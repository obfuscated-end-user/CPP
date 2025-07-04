// https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios

#include <iomanip>
#include <iostream>

int main() {
	std::cout << -12345 << '\n';	// print default value with no field width
	std::cout << std::setw(10) << -12345 << '\n';	// print default with field width
	std::cout << std::setw(10) << std::left << -12345 << '\n';	// print left justified
	std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
	std::cout << std::setw(10) << std::internal << -12345 << "\n\n";	// print internally justified

	std::cout.fill('*');
	std::cout << -12345 << '\n';	// print default value with no field width
	std::cout << std::setw(10) << -12345 << '\n';	// print default with field width
	std::cout << std::setw(10) << std::left << -12345 << '\n';	// print left justified
	std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
	std::cout << std::setw(10) << std::internal << -12345 << '\n';	// print internally justified

	return 0;
}