/*
** EPITECH PROJECT, 2025
** POOL DAY 12
** File description:
** ex00
*/
#include "Picture.hpp"

#pragma once

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN
        };

        Toy();
        Toy(const ToyType &type, const std::string &name, const std::string &file);
        ~Toy();

        ToyType getType() const;
        std::string getName() const;
        void setName(const std::string &name);
        bool setAscii(const std::string &file);
        std::string getAscii() const;

    private:
        ToyType type;
        std::string name;
        std::string ascii;
};
