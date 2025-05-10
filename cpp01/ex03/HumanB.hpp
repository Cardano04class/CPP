#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB(std::string _name);
    void setWeapon(Weapon& arm);
    void attack();
    ~HumanB();
};
