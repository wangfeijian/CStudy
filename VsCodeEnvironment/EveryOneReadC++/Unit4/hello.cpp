#include <iostream>
#include <string>

using namespace std;

int main() {
    string first_name, last_name;
    cout <<"Enter your first name:";
    cin >> first_name;
    cin.ignore(10000, '\n');

    cout <<"Enter your last name:";
    cin >> last_name;
    cin.ignore(10000, '\n');

    cout << "Hello, " << first_name << " " << last_name << "!" << endl;
    cout << "Did you know there are " << first_name.size() + last_name.size() << " characters in your full name?" << endl;
    cout << "press any key to exit...";
    cin.get();
    return 0;
}