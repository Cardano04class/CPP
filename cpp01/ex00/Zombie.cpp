#include "Zombie.hpp"

Zombie::Zombie(std::string newName){
    name = newName;
}

Zombie::~Zombie() {
    std::cout << "Calling the destructor of " << name << std::endl;
}

void Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
