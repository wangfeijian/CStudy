#include <iostream>
#include <string>

class MyClass
{
public:
    MyClass(int *p);
    MyClass(const MyClass &other);
    ~MyClass();
    MyClass &operator=(const MyClass &other);

private:
    int *ptr = nullptr;
};

MyClass::MyClass(int *p)
{
    std::cout << "Entering regular constructor of object of " << this << std::endl;
    ptr = p;
    std::cout << "Exiting regular constructor of object of " << this << std::endl;
}

MyClass::MyClass(const MyClass &other)
{
    std::cout << "Entering copy constructor of object of " << this << std::endl;
    std::cout << "Other object's address is: " << &other << std::endl;
    *this = other;
    std::cout << "Exiting copy constructor of object of " << this << std::endl;
}

MyClass::~MyClass()
{
    std::cout << "Entering destructor of object of " << this << std::endl;
    delete ptr;
    std::cout << "Exiting destructor of object of " << this << std::endl;
}

MyClass &MyClass::operator=(const MyClass &other)
{

    std::cout << "Entering operator= of object of " << this << std::endl;
    std::cout << "Other object's address is: " << &other << std::endl;
    if (this != &other)
    {
        std::cout << "Deleting existing pointer" << std::endl;
        if(ptr != nullptr)
        {
            delete ptr;
        }

        std::cout << "Allocating new memory" << std::endl;
        ptr = new int;
        *ptr = *other.ptr;
    }
    else
    {
        std::cout << "Assigning to self" << std::endl;
    }

    std::cout << "Exiting operator= of object of " << this << std::endl;
    return *this;
}

int main()
{
    std::cout << "----------------------------" << std::endl;
    {
        MyClass obj1(new int(10));
        MyClass obj2(new int(3));
        obj2 = obj1;
    }
    std::cout << "----------------------------" << std::endl;
    {
        MyClass obj3(new int(5));
        MyClass obj4 = obj3;
    }
    std::cout << "----------------------------" << std::endl;
    {
        MyClass obj5(new int(7));
        obj5 = obj5;
    }
    std::cout << "------------------------------" << std::endl;

    std::cout << "press any key to exit";
    std::cin.get();
    return 0;
}