/*
** EPITECH PROJECT, 2025
** POOL DAY 09
** File description:
** ex05
*/
#include <iostream>
#include "IPotion.hpp"
#include "HealthPotion.hpp"
#include "PoisonPotion.hpp"
#include "PowerPotion.hpp"

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

class ICharacter : public IPotion {
    public:
        ICharacter() {};
        virtual ~ICharacter() = default;

        virtual const std::string &getName() const = 0;
        virtual int getPower() const = 0;
        virtual int getHp() const = 0;

        virtual int attack() = 0;
        virtual int special() = 0;
        virtual void rest() = 0;
        virtual void damage(int damage) = 0;

        virtual void drink(const HealthPotion& potion) = 0;
        virtual void drink(const PoisonPotion& potion) = 0;
        virtual void drink(const PowerPotion& potion) = 0;
        virtual void drink(const IPotion& potion) = 0;
};

#endif
