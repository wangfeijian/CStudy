#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

struct Car
{
    char make[20];
    char model[20];
    int year;
};

int main()
{
    std::ofstream outFile("cars.dat", std::ios::binary | std::ios::app);

    if (outFile.is_open())
    {
        Car aCar;
        std::string make, model;

        std::cout << "Enter car's make model and year:[make modle year]\nEnter 'q q 0' to quit\n";
        std::cin >> make >> model >> aCar.year;
        std::cin.ignore(100, '\n');

        while (make != "q" && model != "q" && aCar.year != 0)
        {
            strncpy(aCar.make, make.c_str(), 20);
            strncpy(aCar.model, model.c_str(), 20);
            outFile.write(reinterpret_cast<char *>(&aCar), sizeof(Car));
            std::cout << "The data has been saved successfully.\n";
            std::cout << "Enter car's make model and year:[make modle year]\nEnter 'q q 0' to quit\n";
            std::cin >> make >> model >> aCar.year;
            std::cin.ignore(100, '\n');
        }
        outFile.close();
    }
    else
    {
        std::cout << "Error: unable to open file.\n";
    }

    std::cout<<"press any key to exit.";
    std::cin.get();
    return 0;
}