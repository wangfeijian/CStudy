#include <iostream>
#include <string>

int main()
{
    unsigned int size;
    std::cout << "Please enter the size of the array: ";
    std::cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = size - i;
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << "The value of arr[" << i << "] is " << arr[i] << std::endl;
    }

    delete[] arr;
    arr = nullptr;

    std::cin.ignore(10000, '\n');
    std::cout << "press any key to exit...";
    std::cin.get();
    return 0;
}