#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const std::string &name) : WrongAnimal("WrongCat"), name(name) {
    std::cout << "WrongCat parameterized constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other), name(other.name) {
    std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        this->name = other.name;
    }
    std::cout << "WrongCat copy assignment operator" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Meeehhh??" << std::endl;
}
