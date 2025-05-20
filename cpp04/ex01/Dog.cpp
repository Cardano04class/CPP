#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    this->brain = new Brain();
    std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    this->brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    std::cout << "Dog copy assignment operator" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Bark!!" << std::endl;
}
