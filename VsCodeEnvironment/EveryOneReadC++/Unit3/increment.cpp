#include <iostream>

using namespace std;

int main(){
    int n1 = 1;
    int n2 = 1;

    cout << "At first, n1 is " << n1 << " and n2 is " << n2 << endl;

    n2 = n1++;
    cout << "After n2 = n1++, n1 is " << n1 << " and n2 is " << n2 << endl;

    n2 = n1--;
    cout << "After n2 = n1--, n1 is " << n1 << " and n2 is " << n2 << endl;

    n1 = 1;
    n2 = 1;

    n2 = ++n1;
    cout << "After n2 = ++n1, n1 is " << n1 << " and n2 is " << n2 << endl;

    n2 = --n1;
    cout << "After n2 = --n1, n1 is " << n1 << " and n2 is " << n2 << endl;

    cout << "Size of my var " << sizeof n1 << endl;

    return 0;
}