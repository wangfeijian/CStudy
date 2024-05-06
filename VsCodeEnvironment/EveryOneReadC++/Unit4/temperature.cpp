#include <iostream>
using namespace std;

int main() {
    const unsigned short SUBTRACT_NUM = 32;
    const float TEMPERATURE_SCALE = 5.0/9.0;

    float fahrenheit;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;
    cout << endl;

    cout.setf(ios_base::fixed);
    cout.precision(2);
    cout << fahrenheit << " degrees Fahrenheit is equal to " << (fahrenheit - SUBTRACT_NUM) * TEMPERATURE_SCALE << " degrees Celsius." << endl;
    cin.ignore(10000, '\n');
    cout << "Press any key to exit...";
    cin.get();
    return 0;
}