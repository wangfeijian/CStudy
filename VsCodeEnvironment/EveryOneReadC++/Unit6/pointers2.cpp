#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a = -12;
    float b = 11.11;
    char c = 'A';
    unsigned long d = 1904120522;
    int e = 65535;

    cout << "The value of a is initially: " << a << endl;
    cout << "The value of b is initially: " << b << endl;
    cout << "The value of c is initially: " << c << endl;
    cout << "The value of d is initially: " << d << endl;
    cout << "The value of e is initially: " << e << endl;

    int * aPointer = &a;
    float * bPointer = &b;
    char * cPointer = &c;
    unsigned long * dPointer = &d;
    int * ePointer = &e;

    *aPointer = 3365;
    *bPointer = 3.14159;
    *cPointer = 'Z';
    *dPointer = 1904120523;
    *ePointer = 33674;

    cout << "The value of a is now: " << a << endl;
    cout << "The value of b is now: " << b << endl;
    cout << "The value of c is now: " << c << endl;
    cout << "The value of d is now: " << d << endl;  
    cout << "The value of e is now: " << e << endl;

    cout << "press any key to exit...";

    cin.get();
    return 0;
}