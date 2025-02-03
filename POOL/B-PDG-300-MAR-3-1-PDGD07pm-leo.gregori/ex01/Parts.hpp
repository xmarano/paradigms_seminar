/*
** EPITECH PROJECT, 2025
** POOL DAY 07 pm
** File description:
** ex01
*/
#include <iostream>
#include <string>

#ifndef PARTS_HPP
#define PARTS_HPP

class Arms {
    private:
        std::string _serial;
        bool _functional;

    public:
        Arms(const std::string &serial = "A-01", bool functional = true);
        bool isFunctional() const;
        const std::string &serial() const;
        void informations() const;
};

class Legs {
    private:
        std::string _serial;
        bool _functional;

    public:
        Legs(const std::string &serial = "L-01", bool functional = true);
        bool isFunctional() const;
        const std::string &serial() const;
        void informations() const;
};

class Head {
    private:
        std::string _serial;
        bool _functional;
    
    public:
        Head(const std::string &serial = "H-01", bool functional = true);
        bool isFunctional() const;
        const std::string &serial() const;
        void informations() const;
};

#endif