/*
** EPITECH PROJECT, 2025
** POOL DAY 12
** File description:
** ex00
*/
#include "Toy.hpp"

Toy::Toy() : type(BASIC_TOY), name("toy"), ascii("")
{
}

Toy::Toy(const ToyType &type, const std::string &name, const std::string &file)
{
    this->type = type;
    this->name = name;
    setAscii(file);
}

Toy::~Toy()
{
}

Toy::ToyType Toy::getType() const
{
    return type;
}

std::string Toy::getName() const
{
    return name;
}

void Toy::setName(const std::string &name)
{
    this->name = name;
}

bool Toy::setAscii(const std::string &file)
{
    Picture pic(file);

    if (pic.data == "ERROR") {
        ascii = "ERROR";
        return false;
    }
    ascii = pic.data;
    return true;
}

std::string Toy::getAscii() const
{
    return ascii;
}
