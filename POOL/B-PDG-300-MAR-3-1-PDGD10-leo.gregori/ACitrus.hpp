/*
** EPITECH PROJECT, 2025
** POOL DAY 10
** File description:
** ex00
*/
#include "AFruit.hpp"

#pragma once

class ACitrus : public AFruit {
    public:
        ACitrus(const std::string &name, unsigned int vitamins);
        ~ACitrus() override = default;
};
