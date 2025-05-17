#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap bot("GateBot");

    std::cout << "\n=== Testing attack ===" << std::endl;
    bot.attack("EnemyBot");

    std::cout << "\n=== Testing guardGate ===" << std::endl;
    bot.guardGate();

    std::cout << "\n=== Testing damage and repair ===" << std::endl;
    bot.takeDamage(30);   // Should reduce HP
    bot.beRepaired(20);   // Should increase HP

    std::cout << "\n=== Testing energy exhaustion ===" << std::endl;
    for (int i = 0; i < 51; ++i) {
        bot.attack("DummyTarget"); // Should fail after energyPoints drop to 0
    }

    std::cout << "\n=== Exiting program ===" << std::endl;
    return 0;
}