#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Defauult FragTrap")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap Default constructor" << std::endl;
}

FragTrap::FragTrap (const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap parameterized constructor for " << name << std::endl;
}

FragTrap::FragTrap (const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor" << std::endl;
}

FragTrap &FragTrap::operator= (const FragTrap &rhs)
{
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        std::cout << "FragTrap Copy assignment" << std::endl;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor for " << name << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
         std::cout << "FragTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!\n";
        energyPoints--;
    }
    else
        std::cout << "FragTrap " << name << " cannot attack.\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "High Five " << name << std::endl;
}
