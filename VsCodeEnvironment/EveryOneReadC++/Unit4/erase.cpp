#include <iostream>
#include <string>
using namespace std;

int main() {
    char answer;
    cout << "Would you like to erase your hard disk? (y/n): ";
    cin >> answer;
    cout << endl;

    switch (answer)
    {
        case 'Y':
        case 'y':
            cout << "I'm thinking that's not such a great idea." << endl;        
            break;
        case 'N':
        case 'n':
            cout << "That's a good idea! I'm glad you agree." << endl;
            break;
        default:
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            break;
    }

    cin.ignore(100,'\n');
    cout << "press any key to exit...";
    cin.get();
    return 0;
}