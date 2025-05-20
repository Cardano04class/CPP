#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
    this->brain = new Brain();
    std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    this->brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    std::cout << "Cat copy assignment operator" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meooow" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea) {
    if (this->brain)
        this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    if (this->brain)
        return this->brain->getIdea(index);
    return "";
}
