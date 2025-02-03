/*
** EPITECH PROJECT, 2025
** POOL DAY 08
** File description:
** ex01
*/
#include <iostream>
#include <string>
#include "DroidMemory.hpp"

#ifndef DROID_HPP
#define DROID_HPP

class Droid {
    private:
        std::string _id;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        std::string *_status;
        DroidMemory *_battleData;

    public:
        Droid(const std::string &serial = "");
        Droid(const Droid &other);
        ~Droid();

        // Getters
        const std::string &getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        const std::string *getStatus() const;

        // Setters
        void setId(const std::string &id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);

        // Operators
        bool operator==(const Droid &other) const;
        bool operator!=(const Droid &other) const;
        friend std::ostream &operator<<(std::ostream &os, const Droid &droid);
        Droid &operator<<(size_t &energy);

        // Assignment operator
        Droid &operator=(const Droid &other);

        // Droid memory
        DroidMemory *getBattleData() const;
        void setBattleData(DroidMemory *battleData);
        
        bool operator()(const std::string *task, size_t expRequired);
};

#endif
