/*
** EPITECH PROJECT, 2025
** POOL DAY 12
** File description:
** ex02
*/
#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &file)
{
    setType(Toy::WOODY);
    setName(name);
    setAscii(file);
}

Woody::~Woody()
{
}
