/*
** EPITECH PROJECT, 2025
** POOL DAY 07 pm
** File description:
** ex02
*/
#include <iostream>

#ifndef KREOGCOM_HPP
#define KREOGCOM_HPP

class KreogCom {
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();

        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom() const;

        void ping() const;
        void locateSquad() const;

    private:
        int _x;
        int _y;
        int _serial;
        KreogCom *_next;
};

#endif