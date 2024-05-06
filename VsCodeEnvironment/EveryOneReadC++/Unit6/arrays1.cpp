#include <iostream>
using namespace std;

int main()
{
    const unsigned int SIZE = 5;
    int numbers[SIZE];

    cout << "Enter " << SIZE << " numbers: ";
    for (int i = 0; i < SIZE; i++)
    {
        while (!(cin >> numbers[i]))
        {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    cout << "The numbers you entered are: ";
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
        sum += numbers[i];
    }
    cout << endl;


    cout << "The sum of the numbers is: " << sum << endl;
    cout << "The average of the numbers is: " << (double)sum / SIZE << endl;

    cout<<"Press any key to exit...";
    cin.ignore(10000, '\n');
    cin.get();
    return 0;
}