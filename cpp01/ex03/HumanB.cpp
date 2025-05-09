#include "HumanB.hpp"

HumanB::HumanB(std::string _name){
    name = _name;
}

void HumanB::setWeapon(Weapon arm){
    weapon = arm;
}

void HumanB::attack(){
    std::cout << name << "  attacks with their " << weapon.getType() << std::endl;
}

HumanB::~HumanB(){}
