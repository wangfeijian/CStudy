#include <iostream>
#include <string>

using namespace std;

int main(){
    string first_name, last_name, full_name;

    first_name = "Wang";
    last_name = "Feijian";
    full_name = first_name + " " + last_name;
    cout << "Hello " << full_name << endl;
    cout << full_name << " has " << full_name.length() << " characters." << endl;

    cout<<"press any key to exit.";
    cin.get();
    return 0;
}