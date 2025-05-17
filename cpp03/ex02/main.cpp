#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Creating FragTrap ===" << std::endl;
    FragTrap ft1("Fraggy");

    std::cout << "\n=== Testing attack ===" << std::endl;
    ft1.attack("EnemyBot");

    std::cout << "\n=== Testing damage and repair ===" << std::endl;
    ft1.takeDamage(30);  // Should reduce HP and print result
    ft1.beRepaired(20);  // Should increase HP and print result

    std::cout << "\n=== Testing energy exhaustion ===" << std::endl;
    for (int i = 0; i < 105; i++) // Try to attack until energy runs out
        ft1.attack("DummyTarget");

    std::cout << "\n=== Testing highFivesGuys ===" << std::endl;
    ft1.highFivesGuys();

    std::cout << "\n=== Exiting program ===" << std::endl;
    return 0;
}

