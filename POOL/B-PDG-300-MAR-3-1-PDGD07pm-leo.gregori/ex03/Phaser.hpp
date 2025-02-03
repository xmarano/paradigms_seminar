/*
** EPITECH PROJECT, 2025
** POOL DAY 07 pm
** File description:
** ex03
*/
#include "Sounds.hpp"

#ifndef PHASER_HPP
#define PHASER_HPP

class Phaser {
    public:
        enum AmmoType {
            REGULAR,
            PLASMA,
            ROCKET
        };

        Phaser(int maxAmmo, AmmoType type);
        ~Phaser();

        void fire();
        void ejectClip();
        void changeType(AmmoType newType);
        void reload();
        void addAmmo(AmmoType type);

        int getCurrentAmmos() const;

    private:
        static const int Empty;

        int maxAmmo;
        int currentAmmo;
        AmmoType defaultType;
        std::vector<AmmoType> magazine;
};

#endif
