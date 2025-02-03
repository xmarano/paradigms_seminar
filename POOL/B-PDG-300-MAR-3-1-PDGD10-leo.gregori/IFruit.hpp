/*
** EPITECH PROJECT, 2025
** POOL DAY 10
** File description:
** ex00
*/
#include <string>
#include <ostream>
#include <vector>
#include <iostream>
#include <algorithm>

#pragma once

class IFruit {
    public:
        virtual ~IFruit() = default;
        
        virtual unsigned int getVitamins() const = 0;
        virtual std::string getName() const = 0;
        virtual bool isPeeled() const = 0;
        virtual void peel() = 0;

        friend std::ostream &operator<<(std::ostream &os, const IFruit &fruit);
};

std::ostream &operator<<(std::ostream &os, const IFruit &fruit);
