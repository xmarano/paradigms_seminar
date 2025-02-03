/*
** EPITECH PROJECT, 2025
** POOL DAY 12
** File description:
** ex02
*/
#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &file)
{
    setType(Toy::BUZZ);
    setName(name);
    setAscii(file);
}

Buzz::~Buzz()
{
}
