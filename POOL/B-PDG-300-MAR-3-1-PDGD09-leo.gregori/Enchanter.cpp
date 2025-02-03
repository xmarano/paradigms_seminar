/*
** EPITECH PROJECT, 2025
** POOL DAY 09
** File description:
** ex02
*/
#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << getName() << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    std::cout << getName() << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (getPower() >= 50) {
        std::cout << getName() << " casts a fireball." << std::endl;
        _power -= 50;
        return 99;
    } else {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    }
}

void Enchanter::rest()
{
    if (getHp() > 0) {
        std::cout << getName() << " meditates." << std::endl;
        _power += 100;
        if (_power > 100)
            _power = 100;
    } else {
        std::cout << getName() << " is out of combat." << std::endl;
    }
}
