#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    std::cout << "ScavTrap "<< "attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
}