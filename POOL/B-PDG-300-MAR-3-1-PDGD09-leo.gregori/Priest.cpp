/*
** EPITECH PROJECT, 2025
** POOL DAY 09
** File description:
** ex03
*/
#include "Priest.hpp"

Priest::Priest(const std::string &name, int power) : Peasant(name, power), Enchanter(name, power)
{
    std::cout << name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << getName() << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (getHp() > 0) {
        std::cout << getName() << " prays." << std::endl;
        _power += 100;
        if (_power > 100)
            _power = 100;

        _hp += 100;
        if (_hp > 100)
            _hp = 100;
    } else {
        std::cout << getName() << " is out of combat." << std::endl;
    }
}