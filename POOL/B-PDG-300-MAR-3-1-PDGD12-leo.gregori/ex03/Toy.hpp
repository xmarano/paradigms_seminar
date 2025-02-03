/*
** EPITECH PROJECT, 2025
** POOL DAY 12
** File description:
** ex02
*/
#include "Picture.hpp"

#pragma once

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            CANONICAL,
            BUZZ,
            WOODY
        };

        Toy();
        Toy(const ToyType &type, const std::string &name, const std::string &file);
        ~Toy();

        ToyType getType() const;
        std::string getName() const;
        void setName(const std::string &name);
        bool setAscii(const std::string &file);
        std::string getAscii() const;
        void setType(const ToyType &type);
        void speak(const std::string &statement);

    private:
        ToyType type;
        std::string name;
        std::string ascii;
};
