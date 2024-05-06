#include <iostream>
using namespace std;

int main() {
    unsigned short num = 8;
    unsigned long int sum = 1;
    unsigned short i = 1;

    while (i <= num)
    {
        sum *= i;
        i++;
    }

    cout << "Factorial of " << num << " is " << sum << endl;

    cout << "Press any key to exit...";
    cin.get();
    
    return 0;
}