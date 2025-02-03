/*
** EPITECH PROJECT, 2025
** POOL DAY 09
** File description:
** ex04
*/
#include "Priest.hpp"
#include "Enchanter.hpp"
#include "Knight.hpp"
#include "Peasant.hpp"

#ifndef PALADIN_HPP
#define PALADIN_HPP

class Paladin : public Knight, public Priest {
    public:
        Paladin(const std::string &name, int power);
        ~Paladin();

        int attack() override;
        int special() override;
        void rest() override;
};

#endif
