#include <iostream>
#include <string>

using namespace std;

int main() {
    string quote, author;
    cout << "Enter a quote: ";
    getline(cin, quote);
    cout << "Enter the author: ";
    getline(cin, author);
    cout << "Quote: " << quote << endl;
    cout << "Author: " << author << endl;

    cout << "press any key to exit...";
    cin.get();
    return 0;
}