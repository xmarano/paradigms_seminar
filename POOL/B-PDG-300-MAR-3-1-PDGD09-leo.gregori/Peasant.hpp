/*
** EPITECH PROJECT, 2025
** POOL DAY 09
** File description:
** ex00
*/
#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "HealthPotion.hpp"
#include "PoisonPotion.hpp"
#include "PowerPotion.hpp"


#ifndef PEASANT_HPP
#define PEASANT_HPP

class Peasant : public ICharacter {
    protected:
        const std::string _name;
        int _power;
        int _hp;

    public:
        Peasant(const std::string &name, int power);
        ~Peasant();

        const std::string &getName() const;
        // getters
        int getPower() const;
        int getHp() const;

        virtual int attack();
        virtual int special();
        virtual void rest();
        void damage(int damage);

        void drink(const HealthPotion& potion);
        void drink(const PoisonPotion& potion);
        void drink(const PowerPotion& potion);
        void drink(const IPotion& potion);
        void addHp(int hp);
        void addPower(int power);
};

#endif