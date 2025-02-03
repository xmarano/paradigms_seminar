/*
** EPITECH PROJECT, 2025
** POOL DAY 09
** File description:
** ex02
*/
#include "Peasant.hpp"

#ifndef ENCHANTER_HPP
#define ENCHANTER_HPP

class Enchanter : virtual public Peasant {
    public:
        Enchanter(const std::string &name, int power);
        ~Enchanter();

        int attack() override;
        int special() override;
        void rest() override;
};

#endif
