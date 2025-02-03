/*
** EPITECH PROJECT, 2025
** POOL DAY 09
** File description:
** ex06
*/
#include "IPotion.hpp"
#include <iostream>

#ifndef POWERPOTION_HPP
#define POWERPOTION_HPP

class PowerPotion : public IPotion {
    public:
        const std::string &getName() const;
    protected:
        std::string _name = "Power";
};

#endif
