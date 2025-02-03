/*
** EPITECH PROJECT, 2025
** POOL DAY 10
** File description:
** ex00
*/
#include "IFruit.hpp"

std::ostream &operator<<(std::ostream &os, const IFruit &fruit)
{
    os << "[name: \"" << fruit.getName() << "\", vitamins: " << fruit.getVitamins() << ", peeled: " << (fruit.isPeeled() ? "true" : "false") << "]";
    return os;
}
