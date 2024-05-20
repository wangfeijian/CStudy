#include <iostream>
#include <climits>

unsigned long factorial(unsigned short n);

int main()
{
    unsigned short n;
    std::cout << "Enter a number: ";

    while (!(std::cin >> n) || n < 1)
    {
        std::cout << "Invalid input. Please enter a non-negative integer: ";
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }

    std::cin.ignore(INT_MAX, '\n');

    try
    {
        unsigned long result = factorial(n);
        std::cout << "Factorial of " << n << " is " << result << std::endl;
    }
    catch (const char *msg)
    {
        std::cout << "Error: " << msg << std::endl;
    }

    std::cout << "Press any key to exit...";
    std::cin.get();
    return 0;
}

unsigned long factorial(unsigned short n)
{
    unsigned long result = 1;
    unsigned long max = ULONG_MAX;
    for (int i = 0; i < n; i++)
    {
        result *= (i + 1);
        max /= (i + 1);
    }

    if (max < 1)
    {
        throw "The factorial cannot be calculated.\nPlease use a smaller number.";
    }
    else
    {
        return result;
    }
}
