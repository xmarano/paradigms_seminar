/*
** EPITECH PROJECT, 2025
** POOL DAY 10
** File description:
** ex00
*/
#include "IFruit.hpp"

#pragma once

class AFruit : public IFruit {
    protected:
        std::string name;
        unsigned int vitamins;
        bool peeled;

    public:
        AFruit(const std::string &name, unsigned int vitamins);
        ~AFruit() override = default;

        std::string getName() const override;
        bool isPeeled() const override;
        unsigned int getVitamins() const override;
        void peel() override;
};
