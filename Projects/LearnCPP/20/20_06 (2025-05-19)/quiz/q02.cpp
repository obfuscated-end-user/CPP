// https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions

/*
Use std::sort and a lambda in the following code to sort the seasons by ascending average temperature.

```
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Season
{
  std::string_view name{};
  double averageTemperature{};
};

int main()
{
  std::array<Season, 4> seasons{
    { { "Spring", 285.0 },
      { "Summer", 296.0 },
      { "Fall", 288.0 },
      { "Winter", 263.0 } }
  };

   *
   * Use std::sort here
   *

  for (const auto& season : seasons)
  {
    std::cout << season.name << '\n';
  }

  return 0;
}
```

The program should print

```
Winter
Spring
Fall
Summer
```
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Season {
    std::string_view name {};
    double averageTemperature {};
};

int main() {
    std::array<Season, 4> seasons {
        { { "Spring", 285.0 },
        { "Summer", 296.0 },
        { "Fall", 288.0 },
        { "Winter", 263.0 } }
    };

    // We can compare averageTemperature of the two arguments to
    // sort the array.
    std::sort(seasons.begin(), seasons.end(),
                [](const auto& a, const auto& b) {
                    return a.averageTemperature < b.averageTemperature;
                });

    for (const auto& season : seasons) {
        std::cout << season.name << '\n';
    }

    return 0;
}
