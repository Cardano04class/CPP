#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor for "<< name << std::endl;
}

Dog::Dog(const std::string &name) : Animal("Dog")
{
    this->name = name;
    std::cout << "Dog parameterized constructor for "<< name << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    this->name = other.name;
    std::cout << "Dog copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if(this != &other)
    {
        Animal::operator=(other);
        this->name = other.name;
    }
    std::cout << "Dog copy assignment operator" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor for "<< name << std::endl;
}

void Dog::makeSound() const 
{
    std::cout << "Bark!!" << std::endl;
}
