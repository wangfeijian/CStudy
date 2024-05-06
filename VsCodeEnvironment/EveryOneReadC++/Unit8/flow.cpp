#include <iostream>
using namespace std;

class BaseClass
{
public:
    BaseClass();
    ~BaseClass();
    void DoSomething();
};

class SubClass : public BaseClass
{
public:
    SubClass();
    ~SubClass();
};

BaseClass::BaseClass()
{
    cout << "BaseClass constructor called." << endl;
}

BaseClass::~BaseClass()
{
    cout << "BaseClass destructor called." << endl;
}

void BaseClass::DoSomething()
{
    cout << "BaseClass::DoSomething() called." << endl;
}

SubClass::SubClass()
{
    cout << "SubClass constructor called." << endl;
}

SubClass::~SubClass()
{
    cout << "SubClass destructor called." << endl;
}

void CreateObj()
{
    SubClass obj;
    obj.DoSomething();
}
int main()
{
    SubClass obj;
    obj.DoSomething();
    cout << "press any key to exit.";
    cin.get();
    return 0;
}