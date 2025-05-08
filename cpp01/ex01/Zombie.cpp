#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie(){
    std::cout << name << " has been destroyed.\n";
}

void Zombie::assignName(std::string newName)
{
    name = newName;
}

void Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
