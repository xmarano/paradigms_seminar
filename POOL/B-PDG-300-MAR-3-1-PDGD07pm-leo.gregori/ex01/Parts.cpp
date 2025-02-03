/*
** EPITECH PROJECT, 2025
** POOL DAY 07 pm
** File description:
** ex01
*/
#include "KoalaBot.hpp"
#include "Parts.hpp"

// Constructor ------------------------------------------
Arms::Arms(const std::string &serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Legs::Legs(const std::string &serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Head::Head(const std::string &serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

// // Destructor -------------------------------------------
// Arms::~Arms()
// {
// }

// Member functions -------------------------------------
// ARMS PART
bool Arms::isFunctional() const
{
    return _functional;
}

const std::string &Arms::serial() const
{
    return _serial;
}

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << _serial << " status : " << (_functional ? "OK" : "KO") << std::endl;
}

// HEAD PART
bool Head::isFunctional() const
{
    return _functional;
}

const std::string &Head::serial() const
{
    return _serial;
}

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << _serial << " status : " << (_functional ? "OK" : "KO") << std::endl;
}

// LEGS PART
bool Legs::isFunctional() const
{
    return _functional;
}

const std::string &Legs::serial() const
{
    return _serial;
}

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << _serial << " status : " << (_functional ? "OK" : "KO") << std::endl;
}
