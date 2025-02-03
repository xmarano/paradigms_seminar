/*
** EPITECH PROJECT, 2025
** POOL DAY 09
** File description:
** ex06
*/
#include "IPotion.hpp"
#include <iostream>

#ifndef POISONPOTION_HPP
#define POISONPOTION_HPP

class PoisonPotion : public IPotion {
    public:
        const std::string &getName() const;
    protected:
        std::string _name = "Poison";
};

#endif
