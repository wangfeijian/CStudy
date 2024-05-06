#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned long loanAmount = 150000;
    float annualInterestRatge = 6.0;
    unsigned short loanLength = 30;
    const unsigned short MONTHS_IN_YEAR = 12;

    float monthlyInterestRate = annualInterestRatge / MONTHS_IN_YEAR;
    monthlyInterestRate /= 100;
    unsigned short numberPayments = loanLength * MONTHS_IN_YEAR;

    float monthlyPayment = 1 - pow((1 + monthlyInterestRate), -numberPayments);
    monthlyPayment = monthlyInterestRate / monthlyPayment;
    monthlyPayment *= loanAmount;

    cout << "Assuming a loan in the amount of $" << loanAmount
    << ", at " << annualInterestRatge
    << "% interest, over " << loanLength
    << " years, the monthly payment would be $";

    cout.setf(ios_base::fixed);
    cout.setf(ios_base::showpoint);
    cout.precision(2);

    cout << monthlyPayment << endl;
    cout << "press any key to exit...";
    cin.get();
    return 0;
}