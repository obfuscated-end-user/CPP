#include <iostream>
using namespace std;
int main() {

    int intNum = 10;
    float floatNum = 5.0f;
    double doubleNum = 10.5;

    double result = intNum + floatNum * (doubleNum - 1);
    cout <<"expression result: " << result << endl;

    float widen = intNum;
    cout << "widened (int to float): " << widen << endl;

    int narrow = (int)floatNum;
    cout << "narrowed (float to int): " << narrow << endl;

    return 0;
}