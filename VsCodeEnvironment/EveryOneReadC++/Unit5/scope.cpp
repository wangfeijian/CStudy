#include <iostream>
#include <string>

using namespace std;

void PropmtWait();
void NameChange();

string gName;

int main() {
    string name = "Andi";
    gName = name;
    cout << "At first name is:" << name << " and global name is:"<< gName << endl;

    NameChange();

    cout << "After name change, name is:" << name << " and global name is:"<< gName << endl;

    PropmtWait();
    return 0;
}


void PropmtWait() {
    cin.ignore(10000, '\n');
    cout << "Press any key to continue...";
    getchar();
}

void NameChange() {
    string name = "Larry";
    cout << "In the functhin, At first name is:" << name << " and global name is:"<< gName << endl;

    gName = name;

    cout << "In the functhin, After name change, name is:" << name << " and global name is:"<< gName << endl;
}