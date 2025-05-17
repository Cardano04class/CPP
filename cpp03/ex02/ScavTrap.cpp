#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default ScavTrap")
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap Default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap parameterized constructor for " << name << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        std::cout << "ScavTrap Copy Assignment" << std::endl;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor for " << name << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        std::cout << "ScavTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!\n";
        energyPoints--;
    }
    else    
        std::cout << "ScavTrap " << name << " cannot attack.\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " has entered Gate keeper mode" << std::endl;
}