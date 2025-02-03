/*
** EPITECH PROJECT, 2025
** POOL DAY 12
** File description:
** ex02
*/
#include "Toy.hpp"

#pragma once

class Woody : public Toy {
    public:
        Woody(const std::string &name, const std::string &file = "woody.txt");
        ~Woody();
};
