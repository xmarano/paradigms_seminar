/*
** EPITECH PROJECT, 2025
** POOL DAY 09
** File description:
** ex03
*/
#include "Enchanter.hpp"

#ifndef PRIEST_HPP
#define PRIEST_HPP

class Priest : public Enchanter {
    public:
        Priest(const std::string &name, int power);
        ~Priest();

        void rest() override;
};

#endif
