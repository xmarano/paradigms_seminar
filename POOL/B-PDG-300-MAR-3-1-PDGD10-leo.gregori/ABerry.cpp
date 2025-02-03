/*
** EPITECH PROJECT, 2025
** POOL DAY 10
** File description:
** ex00
*/
#include "ABerry.hpp"

ABerry::ABerry(const std::string &name, unsigned int vitamins) : AFruit(name, vitamins)
{
    peeled = true;
}

void ABerry::peel()
{
}
