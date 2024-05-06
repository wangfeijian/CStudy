#include <iostream>
using namespace std;

void PropmtWait();
void DollarsToEuros(float rate, unsigned dollars);
void DollarsToEuros(float rate, float dollars);

int main() 
{
    float conversionRate = 0.85;
    unsigned dollarsU;
    float dollarsF;

    DollarsToEuros(conversionRate, (unsigned)1);
    cout << "Enter the amount of dollars you want to convert: [####]";

    while (!(cin >> dollarsU))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter dollars: [####]";
    }

    DollarsToEuros(conversionRate, dollarsU);

    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Enter the amount of dollars you want to convert: [##.##]";

    while (!(cin >> dollarsF))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter dollars: [####]";
    }

    DollarsToEuros(conversionRate, dollarsF);

    PropmtWait();
    return 0;
}

void PropmtWait() {
    cin.ignore(10000, '\n');
    cout << "Press any key to continue...";
    getchar();
}

void DollarsToEuros(float rate, unsigned dollars)
{
    cout.setf(ios_base::fixed);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    cout << dollars << " dollars is equal to " << dollars * rate << " euros." << endl;
}

void DollarsToEuros(float rate, float dollars)
{
    cout.setf(ios_base::fixed);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    cout << dollars << " dollars is equal to " << dollars * rate << " euros." << endl;
}