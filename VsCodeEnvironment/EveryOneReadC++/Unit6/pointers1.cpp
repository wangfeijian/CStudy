#include <iostream>
using namespace std;

int main()
{
    int a = -12;
    float b = 11.11;
    char c = 'A';
    unsigned long d = 1904120522;
    int e = 65535;

    int * aPointer = &a;
    float * bPointer = &b;
    char * cPointer = &c;
    unsigned long * dPointer = &d;
    int * ePointer = &e;

    cout << "Address of a: " << reinterpret_cast<unsigned long long>(aPointer) << endl;
    cout << "Address of b: " << reinterpret_cast<unsigned long long>(bPointer) << endl;
    cout << "Address of c: " << reinterpret_cast<unsigned long long>(cPointer) << endl;
    cout << "Address of d: " << reinterpret_cast<unsigned long long>(dPointer) << endl;
    cout << "Address of e: " << reinterpret_cast<unsigned long long>(ePointer) << endl;

    cout << "Press any key to exit";
    cin.get();
    return 0;
}