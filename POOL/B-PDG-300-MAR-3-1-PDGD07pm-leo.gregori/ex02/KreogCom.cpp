/*
** EPITECH PROJECT, 2025
** POOL DAY 07 pm
** File description:
** ex02
*/
#include "KreogCom.hpp"

// Constructor ------------------------------------------
KreogCom::KreogCom(int x, int y, int serial)
{
    _x = x;
    _y = y;
    _serial = serial;
    _next = nullptr;
    std::cout << "KreogCom " << _serial << " initialized" << std::endl;
}

// Destructor -------------------------------------------
KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << _serial << " shutting down" << std::endl;
    KreogCom* current = _next;
    while (current) {
        KreogCom* temp = current;
        current = current->_next;
        temp->_next = nullptr;
        delete temp;
    }
}

// Member functions -------------------------------------
void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom* newCom = new KreogCom(x, y, serial);
    newCom->_next = _next;
    _next = newCom;
}

void KreogCom::removeCom()
{
    if (_next) {
        KreogCom* toDelete = _next;
        _next = _next->_next;
        toDelete->_next = nullptr;
        delete toDelete;
    }
}

KreogCom *KreogCom::getCom() const
{
    return _next;
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << _serial << " currently at " << _x << " " << _y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom* current = _next;
    while (current) {
        current->ping();
        current = current->_next;
    }
    ping();
}
