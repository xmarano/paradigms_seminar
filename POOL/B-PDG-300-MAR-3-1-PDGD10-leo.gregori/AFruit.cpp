/*
** EPITECH PROJECT, 2025
** POOL DAY 10
** File description:
** ex00
*/
#include "AFruit.hpp"

AFruit::AFruit(const std::string &name, unsigned int vitamins) : name(name), vitamins(vitamins), peeled(false)
{
}

std::string AFruit::getName() const
{
    return name;
}

bool AFruit::isPeeled() const
{
    return peeled;
}

unsigned int AFruit::getVitamins() const
{
    return isPeeled() ? vitamins : 0;
}

void AFruit::peel()
{
    peeled = true;
}
