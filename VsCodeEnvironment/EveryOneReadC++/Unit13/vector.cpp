#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> myVector;
    
    myVector.push_back("Hello");
    myVector.push_back("World");

    // for (int i = 0; i < myVector.size(); i++)
    // {
    //     std::cout << myVector[i] << std::endl;
    // }
    std::vector<std::string>::iterator it = myVector.begin();

    while (it!= myVector.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    
    
    std::cout << "press any key to exit...";
    std::cin.get();
    return 0;
}