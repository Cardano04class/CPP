#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string _name) : name(_name), weapon(nullptr) {}

void HumanB::setWeapon(Weapon& arm) {
    weapon = &arm;
}

void HumanB::attack() {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

HumanB::~HumanB() {}
