/*
** EPITECH PROJECT, 2025
** POOL DAY 07 pm
** File description:
** ex00
*/
#include <iostream>

#ifndef SKAT_HPP
#define SKAT_HPP

class Skat {
    private:
        std::string _name;
        int _stimPaks;

    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();

        int &stimPaks();
        const std::string &name();

        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();
};

#endif