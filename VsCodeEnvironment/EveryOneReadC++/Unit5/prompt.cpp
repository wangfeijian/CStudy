#include <iostream>

using namespace std;

void propmtWait();

int main() {
    cout << "start call propmtWait()" << endl;
    propmtWait();
    return 0;
}

void propmtWait() {
    cout << "Press any key to continue...";
    getchar();
}