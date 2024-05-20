#include <iostream>
#include <string>

class Company
{
public:
    Company(std::string name);
    virtual void PrintInfo();

protected:
    std::string m_name;
};

Company::Company(std::string name)
{
    m_name = name;
}

void Company::PrintInfo()
{

    std::cout << "This is a companey called. " << "Company Name: " << m_name << std::endl;
}

class Publisher : public Company
{
public:
    Publisher(std::string name, int books);
    void PrintInfo();

private:
    int m_books;
};

Publisher::Publisher(std::string name, int books) : Company(name)
{
    m_books = books;
}

void Publisher::PrintInfo()
{
    std::cout << "This is a publisher called. " << "Publisher Name: " << m_name << " Number of books: " << m_books << std::endl;
}

int main()
{
    Company *company = new Company("Google");
    company->PrintInfo();
    delete company;
    company = new Publisher("Wiley", 1000);
    company->PrintInfo();
    delete company;
    company = nullptr;
    
    std::cout << "press any key to exit...";
    std::cin.get();
    return 0;
}