#include <iostream>

int main()
{
    int *p = new int;

    std::cout << "Memory address of p: " << p << std::endl;

    delete p;
    p = nullptr;

    std::cout << "press any key to exit...";
    std::cin.get();
    return 0;
}