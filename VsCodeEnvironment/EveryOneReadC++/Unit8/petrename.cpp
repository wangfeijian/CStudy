#include <iostream>
#include <string>

using namespace std;

class Pet
{
public:
    Pet(string name);

    void Eat();
    void Sleep();

protected:
    string Name;

    friend class PetRename;
};

Pet::Pet(string name)
{
    Name = name;
}

void Pet::Eat()
{
    cout << Name << " is eating." << endl;
}

void Pet::Sleep()
{
    cout << Name << " is sleeping." << endl;
}

class Dog : public Pet
{
public:
    Dog(string name);
    void Bark();
};

Dog::Dog(string name) : Pet(name)
{
}

void Dog::Bark()
{
    cout << Name << " is barking." << endl;
}

class Cat : public Pet
{
public:
    Cat(string name);
    void Meow();
};

Cat::Cat(string name) : Pet(name)
{
}

void Cat::Meow()
{
    cout << Name << " is meowing." << endl;
}

class PetRename
{
public:
    PetRename(string name);
    void Rename(Pet *pet, string newName);

private:
    string Name;
};

PetRename::PetRename(string name)
{
    this->Name = name;
}

void PetRename :: Rename(Pet *pet, string newName)
{
    pet->Name = newName;
}

int main()
{
    Cat cat("Fluffy");
    Dog dog("Buddy");

    PetRename pr("Pet");

    cat.Sleep();
    pr.Rename(&cat, "xiao mao");
    cat.Sleep();

    dog.Eat();
    pr.Rename(&dog, "wang wang");
    dog.Eat();

    cout << "press any key to exit.";
    cin.get();

    return 0;
}