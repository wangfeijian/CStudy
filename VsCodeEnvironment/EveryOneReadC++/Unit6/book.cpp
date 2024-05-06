#include <iostream>
#include <string>
using namespace std;

struct book
{
    string title;
    string author;
    unsigned int year;
};

int main()
{
    book myBook;

    cout << "Enter book title: ";
    getline(cin, myBook.title);

    cout << "Enter book author: ";
    getline(cin, myBook.author);

    cout << "Enter book year: ";
    cin >> myBook.year;

    cout << "Title: " << myBook.title << endl;
    cout << "Author: " << myBook.author << endl;
    cout << "Year: " << myBook.year << endl;

    cin.ignore(10000, '\n');
    cout<<"Press any key to exit...";
    cin.get();
    return 0;
}