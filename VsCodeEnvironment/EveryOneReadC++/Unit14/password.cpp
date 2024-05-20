#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char* argv[])
{
    if(argc == 4)
    {
        std::string word1 = argv[1];
        std::string word2 = argv[2];
        char punc = argv[3][0];

        std::string password, insert;

        if(word1.size() > word2.size())
        {
            password = word1;
            insert = word2;
        }
        else
        {
            password = word2;
            insert = word1;
        }
        for (int i = 0; i < insert.size(); i++)
        {
            password.insert(i*2, 1, toupper(insert[i]));
        }
        
        password.replace((password.size()/2),1, 2, punc);
        
        std::cout << "\nYour password is: " << password << std::endl;
    }
    else
    {
        std::cout << "\nUsage: password word1 word2 punctuation" << std::endl;
    }

    std::cout << "\nPress any key to exit..." << std::endl;
    std::cin.get();
    return 0;
}