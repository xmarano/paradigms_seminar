/*
** EPITECH PROJECT, 2025
** POOL DAY 08
** File description:
** ex01
*/
#include <iostream>

#ifndef DROID_MEMORY_HPP
#define DROID_MEMORY_HPP

class DroidMemory {
    private:
        size_t _fingerprint;
        size_t _exp;

    public:
        DroidMemory();
        DroidMemory(const DroidMemory &other);
        ~DroidMemory();

        DroidMemory &operator=(const DroidMemory &other);

        // Getters
        size_t getFingerprint() const;
        size_t getExp() const;

        // Setters
        void setFingerprint(size_t fingerprint);
        void setExp(size_t exp);

        friend std::ostream &operator<<(std::ostream &os, const DroidMemory &memory);

        // Operators
        DroidMemory &operator<<(const DroidMemory &other);
        DroidMemory &operator>>(const DroidMemory &other);
        DroidMemory &operator+=(const DroidMemory &other);
        DroidMemory &operator+=(size_t exp);
        DroidMemory operator+(const DroidMemory &other) const;
        DroidMemory operator+(size_t exp) const;
};

#endif
