#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default constructor" << std::endl;
}

Animal::Animal(const std::string &type)
{
    this->type = type;
    std::cout << "Animal parameterized constructor" << std::endl;
}

Animal::Animal(const Animal &other)
{
    this->type = other.type;
    std::cout << "Animal copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "Animal copy assignment operator" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}