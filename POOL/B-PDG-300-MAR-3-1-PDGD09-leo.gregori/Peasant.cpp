/*
** EPITECH PROJECT, 2025
** POOL DAY 09
** File description:
** ex00
*/
#include "Peasant.hpp"
#include "IPotion.hpp"

Peasant::Peasant(const std::string &name, int power) : _name(name), _power(power), _hp(100)
{
    std::cout << _name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName() const
{
    return _name;
}

int Peasant::getPower() const
{
    return _power;
}

int Peasant::getHp() const
{
    return _hp;
}

int Peasant::attack()
{
    if (getHp() == 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    if (_power < 10) {
        std::cout << _name << " is out of power." << std::endl;
        return 0;
    }
    std::cout << _name << " tosses a stone." << std::endl;
    _power -= 10;
    return 5;
}

int Peasant::special()
{
    if (getHp() > 0) {
        std::cout << _name << " doesn't know any special move." << std::endl;
        return 0;
    } else {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
}

void Peasant::rest()
{
    if (getHp() > 0) {
        std::cout << _name << " takes a nap." << std::endl;
        _power = std::min(100, _power + 30);
    } else {
        std::cout << _name << " is out of combat." << std::endl;
    }
}

void Peasant::damage(int damage)
{
    _hp = std::max(0, _hp - damage);
    if (_hp == 0)
        std::cout << _name << " is out of combat." << std::endl;
    else
        std::cout << _name << " takes " << damage << " damage." << std::endl;

}

void Peasant::addHp(int Hp)
{
    _hp += Hp;
    if (_hp > 100)
        _hp = 100;
    if(_hp < 0)
        _hp = 0;

}

void Peasant::addPower(int power)
{
    _power += power;
    if (_power > 100)
        _power = 100;

}

void Peasant::drink(const HealthPotion& potion)
{
    potion.getName();
    addHp(50);
    std::cout << _name << " feels rejuvenated." << std::endl;
}

void Peasant::drink(const PowerPotion& potion)
{
    potion.getName();
    addPower(50);
    std::cout << _name << "'s power is restored." << std::endl;
}

void Peasant::drink(const PoisonPotion& potion)
{
    potion.getName();
    addHp(-50);
    std::cout << _name << " has been poisoned." << std::endl;
}

void Peasant::drink(const IPotion& potion)
{
    if (potion.getName() == "Health")
        addHp(50);
    if (potion.getName() == "Power")
        addPower(50);
    if (potion.getName() == "Poison")
        addHp(-50);
    std::cout << _name << " drinks a mysterious potion." << std::endl;
}
