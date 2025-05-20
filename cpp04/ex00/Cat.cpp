#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor for " << name << std::endl;
}

Cat::Cat(const std::string &name) : Animal("Cat")
{
    this->name = name;
    std::cout << "Cat parameterized constructor for " << name << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    this->name = other.name;
    std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if(this != &other)
    {
        Animal::operator=(other);
        this->name = other.name;
    }
    std::cout << "Cat copy assignment operator" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor for " << name << std::endl;
}

void Cat::makeSound() const 
{
    std::cout << "Meooow" << std::endl;
} 