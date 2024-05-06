#include <iostream>
using namespace std;

void swap(int& a, int& b);

int main()
{
    int num1 = 10, num2 = 20;

    cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << endl;

    swap(num1, num2);

    cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << endl;

    cout << "press any key to exit:";
    cin.get();
    return 0;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}