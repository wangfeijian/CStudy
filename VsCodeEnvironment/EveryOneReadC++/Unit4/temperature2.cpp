#include <iostream>
using namespace std;

int main() {
    const float RATIO = 5.0/9.0;
    const unsigned short ADD_SUB = 32;
    float tempIn, tempOut;
    char inType, outType;

    cout << "Enter a temperature and indicate the type (C or F) and a number ->[##.# C/F]: ";
    cin >> tempIn >> inType;
    cin.ignore(10000, '\n');

    cout << endl;

    switch (inType)
    {
        case 'C':
        case 'c':
            tempOut = (tempIn / RATIO) + ADD_SUB;
            inType = 'C';
            outType = 'F';
            break;
        case 'F':
        case 'f':
            tempOut = (tempIn - ADD_SUB) * RATIO;
            inType = 'F';
            outType = 'C';
            break;
        default:
            cout << "Invalid input type. Please enter C or F." << endl;
            outType = 'E';
            break;
    }

    cout.setf(ios_base::fixed);
    cout.precision(2);
    if (outType != 'E') {
        cout << tempIn << " " << inType << " is equal to " << tempOut << " " << outType << endl;
    }

    cout << "press any key to exit...";
    cin.get();
    return 0;
}