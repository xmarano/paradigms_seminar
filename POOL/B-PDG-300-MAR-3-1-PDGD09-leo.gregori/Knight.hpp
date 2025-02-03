/*
** EPITECH PROJECT, 2025
** POOL DAY 09
** File description:
** ex01
*/
#include "Peasant.hpp"

#ifndef KNIGHT_HPP
#define KNIGHT_HPP

class Knight : virtual public Peasant {
    public:
        Knight(const std::string &name, int power);
        ~Knight();

        int attack() override;
        int special() override;
        void rest() override;
};

#endif
