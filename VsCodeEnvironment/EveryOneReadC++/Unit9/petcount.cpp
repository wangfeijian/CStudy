#include <iostream>
#include <string>

using namespace std;

class Pet
{
public:
    Pet(string name);
    ~Pet();
    void Eat();
    static int GetCount();

protected:
    string Name;

private:
    static int Count;
};

class Dog : public Pet
{
public:
    Dog(string name);
    void Bark();
};

class Cat : public Pet
{
public:
    Cat(string name);
    void Climb();
};

int Pet::Count = 0;

int Pet::GetCount()
{
    return Count;
}

Pet::Pet(string name)
{
    this->Name = name;
    Count++;
}

Pet::~Pet()
{
    Count--;
}

void Pet::Eat()
{
    cout << Name << " eating..." << endl;
}

Dog::Dog(string name) : Pet(name)
{
}

void Dog::Bark()
{
    cout << Name << " barking..." << endl;
}

Cat::Cat(string name) : Pet(name)
{
}

void Cat::Climb()
{
    cout << Name << " climbing..." << endl;
}

int main()
{
    Dog dog("Buddy");
    Cat cat("Whiskers");

    dog.Eat();
    cat.Eat();

    {
        Dog anotherDog("Rufus");
        anotherDog.Eat();
        cout << "Total pets: " << Pet::GetCount() << endl;
    }
    cout << "Total pets: " << Pet::GetCount() << endl;

    cout << "press any key to exit...";
    cin.get();
    return 0;
}