/*
** EPITECH PROJECT, 2025
** POOL DAY 10
** File description:
** ex00
*/
#include "AFruit.hpp"

#pragma once

class ANut : public AFruit {
    public:
        ANut(const std::string &name, unsigned int vitamins);
        ~ANut() override = default;
};