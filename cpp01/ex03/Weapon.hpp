#ifndef WEAPON_HPP 
#define WEAPON_HPP

#include <iostream>

class Weapon{
    private:
        std::string type;

    public:
        Weapon();
        Weapon(std::string arm);
        ~Weapon();
        const std::string& getType() const;
        void setType(std::string newType);
};

#endif