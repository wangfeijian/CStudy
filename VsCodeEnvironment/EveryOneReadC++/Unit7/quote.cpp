#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class StoreQuote
{
public:
    string quote, speaker;
    ofstream fileOutput;
    StoreQuote();
    ~StoreQuote();

    void InputQuote();
    void InputSpeaker();
    bool Write();
};

StoreQuote::StoreQuote()
{
    fileOutput.open("quotes.txt", ios::app);
}

StoreQuote::~StoreQuote()
{
    fileOutput.close();
}

void StoreQuote::InputQuote()
{
    cout << "Enter the quote: ";
    getline(cin, quote);
}

void StoreQuote::InputSpeaker()
{
    cout << "Enter the speaker: ";
    getline(cin, speaker);
}

bool StoreQuote::Write()
{
    if (quote.empty() || speaker.empty())
    {
        cout << "Quote or speaker is empty." << endl;
        return false;
    }
    if (fileOutput.is_open())
    {
        fileOutput << speaker << " says: " << quote << endl;
        return true;
    }
    return false;
}

int main()
{
    StoreQuote quoteObj;
    quoteObj.InputQuote();
    quoteObj.InputSpeaker();
    if (quoteObj.Write())
    {
        cout << "Quote saved successfully." << endl;
    }

    cout << "Press any key to exit..." << endl;
    getchar();
    return 0;
}