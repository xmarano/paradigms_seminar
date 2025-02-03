/*
** EPITECH PROJECT, 2025
** POOL DAY 10
** File description:
** ex00
*/
#include "AFruit.hpp"

#pragma once

class ABerry : public AFruit {
    public:
        ABerry(const std::string &name, unsigned int vitamins);
        ~ABerry() override = default;

        void peel() override;
};
