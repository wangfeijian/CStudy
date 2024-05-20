#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl

class Pet
{
public:
    Pet(std::string name);
    virtual void Eat();
    virtual void Sleep();
    // virtual void Play();
    virtual void Play()=0;
protected:
    std::string name;
};

class Cat : public Pet
{
public:
    Cat(std::string name);
    void Play();
    void Climb();
};

class Dog : public Pet
{
public:
    Dog(std::string name);
    void Play();
    void Bark();
};

Pet::Pet(std::string name)
{
    this->name = name;
}

void Pet::Eat()
{
    LOG(name + " is eating.");
}

void Pet::Sleep()
{
    LOG(name + " is sleeping.");
}

Cat::Cat(std::string name) : Pet(name)
{

}

void Cat::Play()
{
    LOG(name + " is playing with a cat.");
}

void::Cat::Climb()
{
    LOG(name + " is climbing a tree.");
}

Dog::Dog(std::string name) : Pet(name)
{

}

void Dog::Play()
{
    LOG(name + " is playing with a dog.");
}

void Dog::Bark()
{
    LOG(name + " is barking.");
}

int main()
{
    Pet* cat = new Cat("Fluffy");
    Pet* dog = new Dog("Rufus");

    cat->Eat();
    cat->Sleep();
    cat->Play();

    dog->Eat();
    dog->Sleep();
    dog->Play();

    delete cat;
    delete dog;

    LOG("press any key to exit.");
    std::cin.get();
    return 0;
}