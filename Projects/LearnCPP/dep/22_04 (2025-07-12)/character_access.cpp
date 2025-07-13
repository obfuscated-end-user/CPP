// https://www.learncpp.com/cpp-tutorial/stdstring-character-access-and-conversion-to-c-style-arrays

#include <cstring>
#include <iostream>
#include <string>

int main() {
	std::string sSource1 { "abcdefg" };
	std::cout << sSource1[5] << '\n';
	sSource1[5] = 'X';
	std::cout << sSource1 << '\n';

	std::string sSource2 { "abcdefg" };
	std::cout << sSource2.at(5) << '\n';
	sSource2.at(5) = 'X';
	std::cout << sSource2 << '\n';

	std::string sSource3 { "abcdefg" };
	std::cout << std::strlen(sSource3.c_str()) << '\n';

	std::string sSource4 { "abcdefg" };
	const char* szString { "abcdefg" };
	// memcmp compares the first n characters of two C-style strings and returns 0 if they are equal
	if (std::memcmp(sSource4.data(), szString, sSource4.length()) == 0)
		std::cout << "The strings are equal\n";
	else
		std::cout << "The strings are not equal\n";

	std::string sSource5 { "sphinx of black quartz, judge my vow" };
	char szBuf[20];
	int nLength { static_cast<int>(sSource5.copy(szBuf, 5, 10)) };
	szBuf[nLength] = '\0';	// Make sure we terminate the string in the buffer

	std::cout << szBuf << '\n';

	return 0;
}