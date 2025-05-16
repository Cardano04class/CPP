#ifndef  SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ~ScavTrap();
        void attack(const std::string &target);
    private:
        
};

#endif