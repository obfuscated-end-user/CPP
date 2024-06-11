// https://www.learncpp.com/cpp-tutorial/chapter-11-comprehensive-quiz/

/*
Question #3

Write your own function to swap the value of two integer variables. Write a main() function to test it.

Hint: Use reference parameters

void swap(int& a, int& b)
*/

#include <iostream>

// i know this looks stupid but it works
void swap(int& a, int& b) { // you need the ampersands or it won't work
    int c = a;
    a = b;
    b = c;
}

int main() {
    int num1 = 1;
    int num2 = 2;
    std::cout << "Original: " << num1 << ", " << num2 << '\n';
    swap(num1, num2);
    std::cout << "Swapped: " << num1 << ", " << num2;
    return 0;
}

/*
#include <iostream>

// Use reference parameters so we can modify the values of the arguments passed in
void swap(int& a, int& b)
{
  // Temporarily save value of a
  int temp{ a };

  // Put value of b in a
  a = b;
  // Put previous value of a in b
  b = temp;
}

int main()
{
  int a{ 6 };
  int b{ 8 };
  swap(a, b);

  if (a == 8 && b == 6)
    std::cout << "It works!\n";
  else
    std::cout << "It's broken!\n";

  return 0;
}
*/