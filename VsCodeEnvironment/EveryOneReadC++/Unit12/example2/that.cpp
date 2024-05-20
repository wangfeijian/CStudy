#include "header.h"

unsigned short thatNum = 8;
unsigned short headerNum = 5;

bool printMe = true;

unsigned long returnFactorial(unsigned short num)
{
    unsigned long result = 1;
    for (unsigned short i = 1; i <= num; i++)
    {
        result *= i;
    }

    if (printMe)
    {
        return result;
    }
    else
    {
        return 0;
    }
}