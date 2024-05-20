#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

#define LOG(x) std::cout << x << std::endl

class StoreQuote
{
public:
    StoreQuote(std::string filename);
    ~StoreQuote();
    void InputQuote();
    void InputSpeaker();
    bool Write();

private:
    std::string quote, speak;
    std::ofstream outfile;
};

StoreQuote::StoreQuote(std::string filename)
{
    LOG("In constructor opening the file.");

    outfile.open(filename, std::ios::app);

    assert(outfile.is_open());

    LOG("If this prints, the file is open.");
}

StoreQuote::~StoreQuote()
{
    LOG("In the destructor closing the file.");
    outfile.close();
}

void StoreQuote::InputQuote()
{
    std::cout << "Enter the quote: ";
    std::getline(std::cin, quote);
}

void StoreQuote::InputSpeaker()
{
    std::cout << "Enter the speaker: ";
    std::getline(std::cin, speak);
}

bool StoreQuote::Write()
{
    LOG("In the Write function.");

    if (outfile.is_open())
    {
        LOG("File is open, writing to it.");

        outfile << quote << "|" << speak << std::endl;

        return true;
    }
    else
    {
        LOG("File is not open, cannot write to it.");
        return false;
    }
}

int main()
{
    StoreQuote quoteObj("quotes.txt");

    quoteObj.InputQuote();
    quoteObj.InputSpeaker();

    if (quoteObj.Write())
    {
        std::cout << "Quote saved successfully." << std::endl;
    }
    else
    {
        std::cout << "Error saving quote." << std::endl;
    }

    LOG("Press any key to exit.");
    std::cin.get();

    return 0;
}
