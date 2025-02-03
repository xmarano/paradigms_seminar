/*
** EPITECH PROJECT, 2025
** POOL DAY 08
** File description:
** ex01
*/
#include "Droid.hpp"

// Constructor ------------------------------------------
Droid::Droid(const std::string &serial) : _id(serial), _energy(50), _attack(25), _toughness(15), _status(new std::string("Standing by")), _battleData(new DroidMemory())
{
}

// Copy Constructor -------------------------------------
Droid::Droid(const Droid &other) : _id(other._id), _energy(other._energy), _attack(25), _toughness(15), _status(new std::string(*other._status)), _battleData(new DroidMemory(*other._battleData))
{
}

// Destructor -------------------------------------------
Droid::~Droid()
{
    delete _status;
    delete _battleData;
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
        
        delete _battleData; // droid memory
        _battleData = new DroidMemory(*other._battleData);
    }
    return *this;
}


// Getters & setters de DroidMemory ----------------------
DroidMemory *Droid::getBattleData() const
{
    return _battleData;
}

void Droid::setBattleData(DroidMemory *battleData)
{
    delete _battleData;
    _battleData = battleData;
}

bool Droid::operator()(const std::string *task, size_t expRequired)
{
    if (_energy < 10) {
        *_status = "Battery Low";
        delete task;
        return false;
    }

    _energy -= 10;

    if (_battleData->getExp() >= expRequired) {
        *_status = *task + " - Completed!";
        _battleData->setExp(_battleData->getExp() + expRequired / 2);
        delete task;
        return true;
    } else {
        *_status = *task + " - Failed!";
        _battleData->setExp(_battleData->getExp() + expRequired);
        delete task;
        return false;
    }
}
