#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(10){
    std::cout << "Calling default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : hitPoints(10), energyPoints(10), attackDamage(0){
    this->name = name;
    std::cout << "Calling parameterized constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "Calling copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if(this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "Calling copy assignment" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "Calling destructor for " << name << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else
        std::cout << "ClapTrap " << name << " has no energy or is dead" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage! HP now: " << hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repairs itself " << amount
                  << " HP! HP now: " << hitPoints << std::endl;
    }
    else
        std::cout << "ClapTrap " << name << " can't repair. No energy or dead.\n";
}
