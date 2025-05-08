#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string newName ){
    if (N <= 0)
        return nullptr;
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        horde[i].assignName(newName + std::to_string(i));
    }
    return horde;
}
