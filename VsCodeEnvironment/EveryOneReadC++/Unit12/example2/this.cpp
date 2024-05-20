#include <iostream>

#include "header.h"

extern unsigned short thatNum;

static bool printMe = false;

int main()
{
    unsigned short thisNum = 10;

    std::cout << thisNum << "! is equal to " << returnFactorial(thisNum) << std::endl;
    std::cout << thatNum << "! is equal to " << returnFactorial(thatNum) << std::endl;
    std::cout << headerNum << "! is equal to " << returnFactorial(headerNum) << std::endl;

    if (printMe)
    {
        std::cout << "Hello, World!" << std::endl;
    }

    promptAndWait();

    return 0;
}

void promptAndWait()
{
    std::cout << "Press any key to continue...";
    std::cin.get();
}