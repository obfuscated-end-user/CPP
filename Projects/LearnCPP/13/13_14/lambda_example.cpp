// https://www.learncpp.com/cpp-tutorial/static-member-functions

#include <vector>

class MyClass {
public:
    static std::vector<char> s_mychars;
};

// lambdas are well-known for messing up indentations in programming.
std::vector<char> MyClass::s_mychars{
  []{ // The parameter list of lambdas without parameters can be omitted.
      // Inside the lambda we can declare another vector and use a loop.
      std::vector<char> v{};

      for (char ch{ 'a' }; ch <= 'z'; ++ch)
          v.push_back(ch);

      return v;
  }() // Call the lambda right away
};