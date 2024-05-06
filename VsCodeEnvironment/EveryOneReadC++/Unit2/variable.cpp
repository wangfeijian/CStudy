#include <iostream>

using namespace std;

int main(){
    unsigned short quantity;
    float price;
    float taxRate;

    quantity = 5;
    price = 119.99;
    taxRate = 0.06;

    cout.setf(std::ios_base::fixed);
    cout.setf(std::ios_base::showpoint);
    cout.precision(2);
    cout << "The cost of purchasing "
    << quantity << " widgets at $"
    << price << " each, with a tax rate of ";

    cout << ((quantity * price) + (quantity * price * taxRate)) << std::endl;

    cout << "Widget Cost Calculator" << std::endl;

    cout << "Press Enter or Return to Continue" << std::endl;

    cin.get(); 

    return 0;
}