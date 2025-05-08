#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
    private:
        std::string name;
    public:
        void assignName(std::string newName);
        void announce(void);
        Zombie();
        ~Zombie();
};
    Zombie* zombieHorde( int N, std::string name );
#endif