#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string quote, author;
    cout << "Enter a quote: ";
    getline(cin, quote);
    cout << "Enter the author: ";
    getline(cin, author);

    ofstream outfile("quotes.txt", ios::app);
    if (outfile.is_open())
    {
        outfile << author << " says: " << quote << endl;
        outfile.close();
    }
    else
    {
        cout << "Error: Could not open file for writing." << endl;
    }

    cout << "press any key to exit.";
    cin.get();
    return 0;
}