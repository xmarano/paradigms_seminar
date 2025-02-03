/*
** EPITECH PROJECT, 2025
** POOL DAY 12
** File description:
** ex02
*/
#include "Toy.hpp"

#pragma once

class Buzz : public Toy {
    public:
        Buzz(const std::string &name, const std::string &file = "buzz.txt");
        ~Buzz();
};
