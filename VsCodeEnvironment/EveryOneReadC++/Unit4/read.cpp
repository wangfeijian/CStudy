#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string str;
    ifstream file("quotes.txt");
    if (file.is_open()) {
        while (getline(file, str)) {
            cout << str << endl;
        }
    }
    file.close();

    cout << "press any key to exit...";
    getchar();
    return 0;
}