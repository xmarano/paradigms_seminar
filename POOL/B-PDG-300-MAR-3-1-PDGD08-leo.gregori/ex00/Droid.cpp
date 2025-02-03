/*
** EPITECH PROJECT, 2025
** POOL DAY 08
** File description:
** ex00
*/
#include "Droid.hpp"

// Constructor ------------------------------------------
Droid::Droid(const std::string &serial) : _id(serial), _energy(50), _attack(25), _toughness(15), _status(new std::string("Standing by"))
{
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

// Copy Constructor -------------------------------------
Droid::Droid(const Droid &other) : _id(other._id), _energy(other._energy), _attack(25), _toughness(15), _status(new std::string(*other._status))
{
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

// Destructor -------------------------------------------
Droid::~Droid()
{
    delete _status;
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
}

// Member functions -------------------------------------
// Getters ----------------------------
const std::string &Droid::getId() const
{
    return _id;
}

size_t Droid::getEnergy() const
{
    return _energy;
}

size_t Droid::getAttack() const
{
    return _attack;
}

size_t Droid::getToughness() const
{
    return _toughness;
}

const std::string *Droid::getStatus() const
{
    return _status;
}

// Setters ----------------------------
void Droid::setId(const std::string &id)
{
    _id = id;
}

void Droid::setEnergy(size_t energy)
{
    _energy = (energy > 100) ? 100 : energy;
}

void Droid::setStatus(std::string *status)
{
    delete _status;
    _status = status;
}

// Operators --------------------------
bool Droid::operator==(const Droid &other) const
{
    return _id == other._id && _energy == other._energy && *_status == *other._status;
}

bool Droid::operator!=(const Droid &other) const
{
    bool areEqual = (*this == other);
    return !areEqual;
}

std::ostream &operator<<(std::ostream &os, const Droid &droid)
{
    os << "Droid '" << droid._id << "', " << *droid._status << ", " << droid._energy;
    return os;
}

Droid &Droid::operator<<(size_t &energy)
{
    size_t transferableEnergy = std::min(100 - _energy, energy);
    _energy += transferableEnergy;
    energy -= transferableEnergy;
    return *this;
}

// Assignment Operator ----------------------------------
Droid &Droid::operator=(const Droid &other)
{
    if (this != &other) { // Évite l'auto-affectation
        _id = other._id; // Copie l'identifiant
        _energy = other._energy; // Copie l'énergie
        delete _status; // Libère la mémoire de l'ancien statut
        _status = new std::string(*other._status); // Copie le statut (profonde)
        // Les membres _attack et _toughness sont const et déjà initialisés
    }
    return *this;
}
