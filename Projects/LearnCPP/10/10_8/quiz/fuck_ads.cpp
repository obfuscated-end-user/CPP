// https://www.learncpp.com/cpp-tutorial/struct-passing-and-miscellany/

/*
You are running a website, and you are trying to keep track of how much money you make per day from advertising. Declare an advertising struct that keeps track of how many ads you’ve shown to readers, what percentage of ads were clicked on by users, and how much you earned on average from each ad that was clicked. Read in values for each of these fields from the user. Pass the advertising struct to a function that prints each of the values, and then calculates how much you made for that day (multiply all 3 fields together).
*/

#include <iostream>

struct Advertising {
    int adsShown{};
    double adsClickedPercentage{};
    double averageEarned{};
};

void printInformation (Advertising advertising) {
    std::cout << "Ads shown: " << advertising.adsShown << '\n';
    std::cout << "Percentage of ads that were clicked by users: " << advertising.adsClickedPercentage << '\n';
    std::cout << "How much you earned per click on your ad: " << advertising.averageEarned << '\n';
    std::cout << "In that day, you earned: " << advertising.adsShown * advertising.adsClickedPercentage * advertising.averageEarned << '\n';
}

int main() {
    Advertising test {5, 2.0, 99.00};
    printInformation(test);

    return 0;
}

// way off you fucking retard

/*
#include <iostream>

// First we need to define our Advertising struct
struct Advertising
{
    int adsShown {};
    double clickThroughRatePercentage {};
    double averageEarningsPerClick {};
};

Advertising getAdvertising()
{
    Advertising temp;
    std::cout << "How many ads were shown today? ";
    std::cin >> temp.adsShown;
    std::cout << "What percentage of ads were clicked on by users? ";
    std::cin >> temp.clickThroughRatePercentage;
    std::cout << "What was the average earnings per click? ";
    std::cin >> temp.averageEarningsPerClick;
    return temp;
}

void printAdvertising(const Advertising& ad)
{
    std::cout << "Number of ads shown: " << ad.adsShown << '\n';
    std::cout << "Click through rate: " << ad.clickThroughRatePercentage << '\n';
    std::cout << "Average earnings per click: $" << ad.averageEarningsPerClick << '\n';

    // The following line is split up to reduce the length
    // We need to divide ad.clickThroughRatePercentage by 100 because it's a percent of 100, not a multiplier
    std::cout << "Total Earnings: $" <<
        (ad.adsShown * ad.clickThroughRatePercentage / 100 * ad.averageEarningsPerClick) << '\n';
}

int main()
{
    // Declare an Advertising struct variable
    Advertising ad{ getAdvertising() };
    printAdvertising(ad);

    return 0;
}
*/