
#include <iostream>
#include <exception>

class Animal
{

public:
    virtual void eat()
    {
        std::cout << "Animal eats" << std::endl;
    }
    virtual void sleep()
    {
        std::cout << "Animal sleeps" << std::endl;
    }
    virtual ~Animal() = default;
};

class Dog : virtual public Animal
{
public:
    void eat() override
    {
        std::cout << "Dog eats" << std::endl;
    }
};
class Cat : virtual public Animal
{
};

class Hybrid : public Dog, public Cat
{
public:
    // void eat() override
    // {
    //     std::cout << "Hybrid eats" << std::endl;
    // }
};

int main()
{
    Animal *animal = new Dog();
    // Cat *cat = &hybrid;
    // Animal *animal = &hybrid;
    animal->eat(); // Calls Animal's eat
    // dog->eat();    // Calls Dog's eat
    // cat->eat();    // Calls Cat's eat
    Hybrid *hybrid = new Hybrid();
    hybrid->eat();   // Calls Hybrid's eat
    hybrid->sleep(); // Calls Animal's sleep
    return 0;
}