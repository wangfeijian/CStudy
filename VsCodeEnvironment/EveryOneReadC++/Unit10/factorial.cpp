#include <iostream>
#include <climits>

class Factorial
{
public:
    Factorial(unsigned short num = 1);
    bool InRange();
    unsigned long GetFactorial();

private:
    unsigned short num;
};

Factorial::Factorial(unsigned short num)
{
    this->num = num;
}

bool Factorial::InRange()
{
    unsigned long max = ULONG_MAX;

    for (int i = num; i >= 1; i--)
    {
        max /= i;
    }

    return max >= 1;
}

unsigned long Factorial::GetFactorial()
{
    if (num == 1)
        return 1;
    else
        return num * Factorial(num - 1).GetFactorial();
}

int main()
{
    unsigned short num = 1;

    std::cout << "Enter a small number, positive integer: [##]";
    while (!(std::cin >> num) || num < 1)
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid input. Enter a small number, positive integer: [##]";
    }

    Factorial f(num);

    if (f.InRange())
    {

        std::cout << "The factorial of " << num << " is " << f.GetFactorial() << std::endl;
    }
    else
    {
        std::cout << "The factorial of " << num << " is too large to calculate." << std::endl;
    }

    std::cin.ignore(10000, '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}