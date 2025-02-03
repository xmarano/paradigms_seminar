/*
** EPITECH PROJECT, 2025
** POOL DAY 07 pm
** File description:
** ex01
*/
#include "Parts.hpp"

#ifndef KOALABOT_HPP
#define KOALABOT_HPP

class KoalaBot {
    private:
        std::string _serial;
        Arms _arms;
        Legs _legs;
        Head _head;

    public:
        KoalaBot(const std::string &serial = "Bob-01");

        void setParts(const Arms &arms);
        void setParts(const Legs &legs);
        void setParts(const Head &head);

        void swapParts(Arms &arms);
        void swapParts(Legs &legs);
        void swapParts(Head &head);

        void informations() const;
        bool status() const;
};

#endif
