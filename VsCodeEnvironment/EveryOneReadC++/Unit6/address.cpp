#include <iostream>
using namespace std;

int main()
{
    int a = -12;
    float b = 11.11;
    char c = 'A';
    unsigned long d = 1904120522;
    int e = 65535;

    cout << "Address of a: " << (unsigned long long)&a << endl;
    cout << "Address of b: " << (unsigned long long)&b << endl;
    cout << "Address of c: " << (unsigned long long)&c << endl;
    cout << "Address of d: " << (unsigned long long)&d << endl;
    cout << "Address of e: " << (unsigned long long)&e << endl;

    cout << "Press any key to exit";
    cin.get();
    return 0;
}