#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string first_name, last_name;
    cout << "Please enter your first name:";
    cin >> first_name;
    cout << "Please enter your last name:";
    cin >> last_name;
    cout << "Your name is : " << first_name << " " << last_name << endl;
    return 0;
}
