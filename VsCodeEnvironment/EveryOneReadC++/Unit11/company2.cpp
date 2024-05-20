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
    virtual void PrintInfo();
    virtual int GetBooks();

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

int Publisher::GetBooks()
{
    return m_books;
}

Company *CreateCompany(std::string name, int books = 0);

int main()
{
    Company *company = CreateCompany("Google");
    company->PrintInfo();
    delete company;
    company = CreateCompany("Wiley", 1000);
    // Publisher *p = (Publisher*)company;
    Publisher *p = dynamic_cast<Publisher *>(company);
    if (p != nullptr)
    {

        company->PrintInfo();
        std::cout << "Number of books: " << p->GetBooks() << std::endl;
    }
    else
    {
        std::cout << "This is not a publisher." << std::endl;
    }
    delete company;
    company = nullptr;

    std::cout << "press any key to exit...";
    std::cin.get();
    return 0;
}

Company *CreateCompany(std::string name, int books)
{
    if (books > 0)
    {
        return new Publisher(name, books);
    }
    else
    {
        return new Company(name);
    }
}