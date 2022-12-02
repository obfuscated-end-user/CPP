// https://www.learncpp.com/cpp-tutorial/friend-functions-and-classes/

#include <iostream>

// this is here so that the Temparature class knows that there is a Humidity class that will be defined later
class Humidity;

class Temperature {
private:
    int m_temp {};

public:
    Temperature(int temp=0)
        : m_temp { temp }
    {
    }

    // code will fuck up if you remove the class prototype from above
    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

// Humidity defined here
class Humidity {
private:
    int m_humidity {};

public:
    Humidity(int humidity=0)
        : m_humidity { humidity }
    {
    }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

void printWeather(const Temperature& temperature, const Humidity& humidity) {
    std::cout << "The temperature is " << temperature.m_temp << " and the humidity is " << humidity.m_humidity << '\n';
}

int main() {
    Humidity hum{10};
    Temperature temp{12};

    printWeather(temp, hum);

    return 0;
}