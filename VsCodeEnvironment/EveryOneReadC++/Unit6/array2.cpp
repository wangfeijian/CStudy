#include <iostream>
using namespace std;

int main()
{
    const unsigned short ITEMS = 3;

    int intArray[ITEMS] = {98,-486,301589};
    char charArray[ITEMS] = {'a','b','c'};
    double doubleArray[ITEMS] = {3.14, 2.71, 1.618};

    int * intPtr = intArray;
    char * charPtr = charArray;
    double * doublePtr = doubleArray;

    cout << "intArray: " << endl;
    for (int i = 0; i < ITEMS; i++)
    {
        cout << *intPtr << " at " << reinterpret_cast<unsigned long long>(intPtr) << endl;
        intPtr++;
    }

    cout << "charArray: " << endl;
    for (int i = 0; i < ITEMS; i++)
    {
        cout << *charPtr << " at " << reinterpret_cast<unsigned long long>(charPtr) << endl;
        charPtr++;
    }

    cout << "doubleArray: " << endl;
    for (int i = 0; i < ITEMS; i++)
    {
        cout << *doublePtr << " at " << reinterpret_cast<unsigned long long>(doublePtr) << endl;
        doublePtr++;
    }

    cout << "press any key to exit...";
    cin.get();
    return 0;
}