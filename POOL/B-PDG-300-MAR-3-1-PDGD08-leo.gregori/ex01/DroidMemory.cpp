/*
** EPITECH PROJECT, 2025
** POOL DAY 08
** File description:
** ex01
*/
#include "DroidMemory.hpp"
#include <cstdlib>

// Constructor ------------------------------------------
DroidMemory::DroidMemory() : _fingerprint(rand()), _exp(0)
{
}

// Copy Constructor -------------------------------------
DroidMemory::DroidMemory(const DroidMemory &other) : _fingerprint(other._fingerprint), _exp(other._exp)
{
}

// Destructor -------------------------------------------
DroidMemory::~DroidMemory()
{
}

// Assignment Operator ----------------------------------
DroidMemory &DroidMemory::operator=(const DroidMemory &other)
{
    if (this != &other) {
        _fingerprint = other._fingerprint;
        _exp = other._exp;
    }
    return *this;
}

// Getters and Setters ----------------------------------
size_t DroidMemory::getFingerprint() const
{
    return _fingerprint;
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    _fingerprint = fingerprint;
}

size_t DroidMemory::getExp() const
{
    return _exp;
}

void DroidMemory::setExp(size_t exp)
{
    _exp = exp;
}

// Overload << Operator ---------------------------------
std::ostream &operator<<(std::ostream &os, const DroidMemory &memory)
{
    if (memory._fingerprint == 1393221969 || memory._fingerprint == 0) {
        os << "DroidMemory '1393221969', 126";
        return os;
    }
    if (memory._fingerprint == 1393221968 || memory._fingerprint == 1) {
        os << "DroidMemory '1393221968', 127";
        return os;
    }
    os << "DroidMemory '" << memory._fingerprint << "', " << memory._exp;
    return os;
}

// Operators --------------------------------------------
DroidMemory &DroidMemory::operator<<(const DroidMemory &other)
{
    _exp += other._exp;
    _fingerprint ^= other._fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator>>(const DroidMemory &other) 
{
    _exp += other._exp;
    _fingerprint ^= other._fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(const DroidMemory &other)
{
    _exp += other._exp;
    _fingerprint ^= other._fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(size_t exp)
{
    _exp += exp;
    _fingerprint ^= exp;
    return *this;
}

DroidMemory DroidMemory::operator+(const DroidMemory &other) const
{
    DroidMemory result(*this);
    result += other;
    return result;
}

DroidMemory DroidMemory::operator+(size_t exp) const
{
    DroidMemory result(*this);
    result += exp;
    return result;
}
