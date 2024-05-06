#include <iostream>
using namespace std;

void PropmtWait();
void DollarsToEuros(float rate, unsigned short dollars = 1);

int main() 
{
    float conversionRate = 0.85;
    unsigned short dollars;

    DollarsToEuros(conversionRate);
    cout << "Enter the amount of dollars you want to convert: ";
    
    while (!(cin >> dollars))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter dollars: [####]";
    }

    DollarsToEuros(conversionRate, dollars);

    PropmtWait();
    return 0;
}

void PropmtWait() {
    cin.ignore(10000, '\n');
    cout << "Press any key to continue...";
    getchar();
}

void DollarsToEuros(float rate, unsigned short dollars)
{
    cout.setf(ios_base::fixed);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    cout << dollars << " dollars is equal to " << dollars * rate << " euros." << endl;
}