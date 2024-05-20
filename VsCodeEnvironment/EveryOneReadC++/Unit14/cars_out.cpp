#include <iostream>
#include <string>
#include <fstream>

struct Car
{
    char make[20];
    char model[20];
    int year;
};

int main()
{
    std::ifstream inFile("cars.dat", std::ios::binary);

    if (inFile.is_open())
    {
        Car car;
        std::cout << "The following cars are available: \n";
        while (inFile.read(reinterpret_cast<char *>(&car), sizeof(Car)))
        {
            std::cout << car.make << " " << car.model << " " << car.year << "\n";
        }
        inFile.close();
    }

    std::cout << "press any key to exit...";

    std::cin.get();
    return 0;
}