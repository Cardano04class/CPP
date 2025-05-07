#include "Zombie.hpp"

Zombie::Zombie(std::string _name){
    std::cout << "Calling named constractor" << std::endl;
    name = _name;
}

Zombie::~Zombie() {
    std::cout << "Calling the destractor" << std::endl;
}

void Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
