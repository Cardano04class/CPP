#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Alpha");
    ClapTrap b("Bravo");

    a.attack("Bravo");
    b.takeDamage(3);
    b.beRepaired(2);
    b.attack("Alpha");
}