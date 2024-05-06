#include <iostream>
using namespace std;

int main()
{
    const float RATIO = 5.0 / 9.0;
    const unsigned short ADD_SUB = 32;
    float tempIn, tempOut;
    char inType, outType;

    cout << "Enter temperature: [##.#]";

    while (!(cin >> tempIn))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter temperature: [##.#]";
    }

    do
    {
        cout << "Enter temperature type (C/F): ";
        cin >> inType;
        cin.ignore(10000, '\n');
    } while (inType != 'C' && inType != 'F' && inType != 'c' && inType != 'f');

    cout << endl;

    switch (inType)
    {
        case 'F':
        case 'f':
            tempOut = (tempIn - ADD_SUB) * RATIO;
            outType = 'C';
            break;
        case 'C':
        case 'c':
            tempOut = (tempIn / RATIO) + ADD_SUB;
            outType = 'F';
            break;
    }

    cout.setf(ios_base::fixed);
    cout.precision(2);
    cout << tempIn << " " << inType << " is equal to " << tempOut << " " << outType << endl;

    cout << "press any key to exit...";
    cin.get();
    return 0;
}