#include <iostream>
#include <string>

using namespace std;

class Pet
{
private:
    string Name;

public:
    Pet(string name);
    void Eat();
    void Sleep();
    void SetName(string name);
    string GetName();
    void Play();
};

class Dog : public Pet
{
public:
    Dog(string name);
    void Bark();
    void Play();
    void Bark(int count);
};

class Cat : public Pet
{
public:
    Cat(string name);
    void Meow();
    void Play();
};

Pet::Pet(string name)
{
    this->Name = name;
}

void Pet::Eat()
{
    cout << this->Name << " is eating." << endl;
}

void Pet::Sleep()
{
    cout << this->Name << " is sleeping." << endl;
}

void Pet::SetName(string name)
{
    this->Name = name;
}

string Pet::GetName()
{
    return this->Name;
}

void Pet::Play()
{
    cout << this->Name << " is playing." << endl;
}

Dog::Dog(string name) : Pet(name)
{

}

void Dog::Bark()
{
    cout << this->GetName() << " is barking." << endl;
}

void Dog::Bark(int count)
{
    cout << this->GetName() << " is barking " << count << " times." << endl;
}

void Dog::Play()
{
    Pet::Play();
    cout << this->GetName() << " is playing with a ball." << endl;
}
Cat::Cat(string name) : Pet(name)
{

}

void Cat::Meow()
{
    cout << this->GetName() << " is meowing." << endl;
}

void Cat::Play()
{
    Pet::Play();
    cout << this->GetName() << " is playing with a mouse." << endl;
}

int main()
{
    Dog dog("Buddy");
    Cat cat("Whiskers");
    
    dog.Eat();
    dog.Sleep();
    dog.Bark();
    dog.Bark(3);
    dog.Play();

    cat.Eat();
    cat.Sleep();
    cat.Meow();
    cat.Play();

    cout << "press any key to exit.";
    cin.get();
    return 0;
}