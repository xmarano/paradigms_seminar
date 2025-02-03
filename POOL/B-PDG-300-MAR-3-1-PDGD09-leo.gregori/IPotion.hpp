/*
** EPITECH PROJECT, 2025
** POOL DAY 09
** File description:
** ex06
*/
#include <iostream>
#include <string>

#ifndef IPOTION_HPP
#define IPOTION_HPP

class ICharacter;

class IPotion {
    public:
        IPotion() = default;
        virtual ~IPotion() = default;
        virtual const std::string &getName() const = 0;
};

#endif
