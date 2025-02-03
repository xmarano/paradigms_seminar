/*
** EPITECH PROJECT, 2025
** POOL DAY 09
** File description:
** ex06
*/
#include "IPotion.hpp"
#include <iostream>

#ifndef HEALTHPOTION_HPP
#define HEALTHPOTION_HPP

class HealthPotion : public IPotion {
    public:
        const std::string &getName() const;
    protected:
        std::string _name = "Health";
};

#endif
