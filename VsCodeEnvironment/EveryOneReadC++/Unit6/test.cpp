#include <iostream>
using namespace std;

void ChangeValue(int& oldValue, int newValue);

int main()
{
    int oldValue = 10;

    cout << "Old value: " << oldValue << endl;

    ChangeValue(oldValue, 20);

    cout << "After call the function, old value: " << oldValue << endl;

    cout << "press any key to exit...";
    cin.get();
    return 0;
}

void ChangeValue(int& oldValue, int newValue)
{
    oldValue = newValue;
}