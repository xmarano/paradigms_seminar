/*
** EPITECH PROJECT, 2025
** POOL DAY 10
** File description:
** ex01
*/
#include "IFruit.hpp"

#pragma once

class FruitBox {
    private:
        unsigned int maxSize;
        std::vector<IFruit *> fruits;

    public:
        FruitBox(unsigned int size);
        ~FruitBox();

        unsigned int getSize() const;
        unsigned int nbFruits() const;
        bool pushFruit(IFruit *fruit);
        IFruit *popFruit();

        friend std::ostream &operator<<(std::ostream &os, const FruitBox &box);
};
