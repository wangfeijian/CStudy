#include <iostream>
using namespace std;

void propmtWait();
void ConvertTemperature(float tempIn, char inType);

int main()
{
    float temperatureIn;
    char tempTypeIn;

    cout << "Enter temperature: [##.#]";

    while (!(cin >> temperatureIn))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter temperature: [##.#]";
    }

    do
    {
        cout << "Enter temperature type (C/F): ";
        cin >> tempTypeIn;
        cin.ignore(10000, '\n');
    } while (tempTypeIn != 'C' && tempTypeIn != 'F' && tempTypeIn != 'c' && tempTypeIn != 'f');

    cout << endl;

    ConvertTemperature(temperatureIn, tempTypeIn);

    propmtWait();

    return 0;
}

void propmtWait() {
    cout << "Press any key to continue...";
    getchar();
}

void ConvertTemperature(float tempIn, char inType)
{
    const float RATIO = 5.0/9.0;
    const unsigned short ADD_SUB = 32;
    float tempOut;
    char  outType;

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
    }

    cout.setf(ios_base::fixed);
    cout.precision(2);
    cout << tempIn << " " << inType << " is equal to " << tempOut << " " << outType << endl;
}